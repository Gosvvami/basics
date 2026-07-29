import json
import numpy as np
import matplotlib.pyplot as plt

# Loading JSON content
with open("results.json", "r") as results:
    data = json.load(results)

# Extracting Data
input_sizes_bruteforce = []
cpu_times_bruteforce = []

input_sizes_mergesort = []
cpu_times_mergesort = []

for item in data["benchmarks"]:

    name = item["name"]
    cpu_time = item["cpu_time"]
    size = int(name.split("/")[-1])

    if (name.startswith("BM_BRUTEFORCE")):
        input_sizes_bruteforce.append(size)
        cpu_times_bruteforce.append(cpu_time)

    else:
        input_sizes_mergesort.append(size)
        cpu_times_mergesort.append(cpu_time)
    

# plotting the results of bruteforce
plt.figure(figsize=(8,6),facecolor='paleturquoise')
plt.plot(input_sizes_bruteforce,np.array(cpu_times_bruteforce)/1e9, 'go-', label = "BruteForce")
plt.xlabel("Number of Nodes")
plt.ylabel("Time (seconds)")
plt.title("Brute Force Sorting on Singly Linked List")
plt.grid(True)
plt.legend()

plt.savefig("benchmark_plot_bruteforce.png", dpi=300)

# plotting the results of mergesort
plt.figure(figsize=(8,6),facecolor='paleturquoise')
plt.plot(input_sizes_mergesort,np.array(cpu_times_mergesort)/1e9, 'bo-', label = "MergeSort")
plt.xlabel("Number of Nodes")
plt.ylabel("Time (seconds)")
plt.title("Merge Sort on Singly Linked List")
plt.grid(True)
plt.legend()

plt.savefig("benchmark_plot_mergesort.png", dpi=300)

# plotting the results of comparing bruteforce & mergesort
plt.figure(figsize=(8,6),facecolor='thistle')
plt.plot(input_sizes_mergesort,np.array(cpu_times_mergesort)/1e9, 'bo-', label = "MergeSort")
plt.plot(input_sizes_bruteforce,np.array(cpu_times_bruteforce)/1e9, 'go-', label = "BruteForce")
plt.xlabel("Number of Nodes")
plt.ylabel("Time (seconds)")
plt.title("Merge Sort v. Brute Force Sort on Singly Linked List")
plt.grid(True)
plt.legend()

plt.savefig("benchmark_plot_comparisons.png", dpi=300)

   



