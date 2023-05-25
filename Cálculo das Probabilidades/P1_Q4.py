import numpy as np
from scipy.stats import hypergeom
import matplotlib.pyplot as plt


def questao_4():
    [M, n, N] = [100, 2, 6]
    rv = hypergeom(M, n, N)
    x = np.arange(0, n + 1)
    pmf_dogs = rv.pmf(x)



questao_4()