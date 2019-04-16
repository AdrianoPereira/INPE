import numpy as np
from math import ceil, log2, sqrt
from statistics import stdev, mean


def pmodel(noValues=256, p=0.375, slope=None):
	# Calculate length of time series
	noOrders = ceil(log2(noValues))
	noValuesGenerated = 2**noOrders

	# y is the time series generated with the p-model.
	y = 1
	for n in range(0, noOrders):
		y = next_step_1d(y, p) 


	if slope:
		fourierCoeff = fractal_spectrum_1d(noValues, slope/2).T
		
		meanVal = mean(y)
		stdy = stdev(y)
		# dp = lambda value: sqrt(sum((value - mean(value))*(value - mean(value)))/len(value)-1)
		
		x = np.fft.ifft(y - meanVal)
		phase = np.angle(x)
		x = fourierCoeff * np.exp(1j*phase)
		x = np.real(np.fft.fft(x))
		# print('x ', x)
		# print(x)
		x = x * stdy / stdev(x)
		x = x + meanVal
	else:
		x = y

	return np.round(x, decimals=5)

def next_step_1d(y, p):
	size = np.size(y) #1 if type(y) == int else len(y)
	y2 = np.zeros(size*2) #np.array([0.0 for n in range(size*2)])
	np.random.seed(123)
	sign = np.random.random(size)-0.5
	sign /= abs(sign)

	y2[0:2*size-1:2] = y + sign*(1-2*p)*y
	y2[1:2*size:2] = y - sign*(1-2*p)*y

	return y2

def fractal_spectrum_1d(noValues, slope):
	ori_vector_size = noValues
	ori_half_size   = ori_vector_size/2
	a = np.array([0.0 for n in range(ori_vector_size+1)])
	ori_half_size = int(ori_half_size+2)

	for t2 in range(1, ori_half_size):
		index = t2-1
		t4 = 2 + ori_vector_size - t2

		if t4 > ori_half_size:
			t4 = t2
		if index <= 0:
			coeff = 0
		else:
			coeff = np.power(index, slope)

		a[t2] = coeff
		a[t4] = coeff

	a[1] = 0

	return a[1:]
# old = sorted(list([2.06609, 0.9813, 0.55784, 0.39476]))
new = sorted(list(pmodel(4, 0.52, -1.66)))
# print(old == new) # [2.12111 0.68803 0.50282 0.68803]
# print(old)
print(new)
