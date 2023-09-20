import numpy as np
import pandas as pd
import matplotlib.pyplot as plots
import random
from datascience import *


a=Table().read_table("C:\code_space\Self-Study\Python\\2015-summary.csv")

delay_bins = np.arange(-20, 201, 10)
a.hist('Delay', bins=delay_bins, unit='minute')
plots.title("Population Distribution of 2015 Flight Delays")


