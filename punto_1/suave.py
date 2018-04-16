import numpy as num
import matplotlib.pyplot as plt
from PIL import Image

#Se lee la imagen
im = Image.open('image.png')
im = num.array(im)
plt.imshow(im)

im1 = im*0 + 1j*0

#Funcion para la transformada de fourier
def fourier(a):
    i = 0;
    while i<num.size(a,0):
        j = 0;
        while j<num.size(a,1):
            i1 = 0;
            while i1<num.size(a,0):
                j1 = 0;
                while j1<num.size(a,1):
                    im1[i,j] += a[i1,j1]*num.cos(-2*3.1415*(i*i1/num.size(a,0) + j*j1/num.size(a,1)))
                    im1[i,j] += 1j*a[i1,j1]*num.sin(-2*3.1415*(i*i1/num.size(a,0) + j*j1/num.size(a,1)))
                    j1 += 1 
                i1 += 1 
            j += 1 
        i += 1 
    return im1
    
#Funcion para crear el kernel del suavizado gaussiano
def kernel(a):
    x = num.size(a, 0)
    y = num.size(a, 1)
    M = num.zeros((x, y))
    for i in range(10):
        for j in range(10):
            i1 = i + 5
            j1 = j + 5
            M[i,j] = num.exp(-0.2*(i1**2+j1**2))
    return M 

#Se encuentra el nuevo espectro de la imagen
def espectro(a):
    im2 = kernel(a)*0 + 0.0j
    f=fourier(a)
    k=kernel(a)
    x = num.size(kernel(a), 0)
    y = num.size(kernel(a), 1)
    for i in range(x):
        for j in range(y):
            im2[i,j] = f[i,j]*k[i,j]
    return im2
    
#Se guarda la imagen
imagen = espectro(im)  
plt.imshow(imagen.real, cmap='gray')
plt.savefig("suave.png")
