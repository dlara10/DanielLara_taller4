import numpy as num
import matplotlib.pyplot as plt
from scipy import fftpack
from PIL import Image

#Se lee la imagen
im = Image.open('image.png')
im = num.array(im)
plt.imshow(im)
altas = 0.7
bajas = 0.2

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

#Filtro alto
def filtroalto(a, filtro):
	imf = fourier(a).copy()
	x,y = imf.shape
	xmin = num.argmin(x)
	ymin = num.argmin(y)
	imf[int(xmin):int(x*filtro)] = 0
	imf[:, int(ymin):int(y*filtro)] = 0
	return imf

#Filtro bajo
def filtrobajo(a, filtro):
	imf = fourier(a).copy()
	x,y = imf.shape
	xmax = num.argmax(x)
	ymax= num.argmax(y)
	imf[int(x*filtro):int(xmax)] = 0
	imf[:, int(y*filtro):int(ymax)] = 0
	return imf

#Transformada filtro

def inversa(filtro):
	return fftpack.ifft2(filtro).real
#Imprimir imagen
def filtro(nombre):
	#Filtro alto
	if nombre == alto:
		imagen = fftpack.ifft2(filtroalto(im, altas)).real
		#Se guarda la imagen
		plt.figure()
		plt.imshow(imagen.real, cmap='gray')
		plt.savefig("altas.png")
	#Filtro bajo
	if nombre == bajo:
		imagen = fftpack.ifft2(filtrobajo(im, bajas)).real
	#Se guarda la imagen
		plt.figure()
		plt.imshow(imagen.real, cmap='gray')
		plt.savefig("bajas.png")
	
		
	
	
	
