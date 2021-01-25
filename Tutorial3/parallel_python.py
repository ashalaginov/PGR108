from joblib import Parallel, delayed
import multiprocessing 

print("Number of processors: ", multiprocessing.cpu_count())

# Number of cores
num_cores = multiprocessing.cpu_count()
N=1 
#N=num_cores

# Create a for loop
inputs = range(20) 
def processInput(n):
    for i in range (1,10000000):
        i=i*i/i*i
    print("Thread id: ",n)

# Execute the jobs in parallel      
results = Parallel(n_jobs=N)(delayed(processInput)(n) for n in inputs)