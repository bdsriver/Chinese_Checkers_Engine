import csv
import matplotlib.pyplot as plt

# CSV files and corresponding number of CPU cores
files = {
    "timing_results1.csv": 1,
    "timing_results2.csv": 2,
    "timing_results4.csv": 4,
    "timing_results8.csv": 8,
    "timing_results16.csv": 16,
}

depths = {}
speedup = {}
efficiency = {}
speedup_omp = {}
efficiency_omp = {}

# Read data from CSV files
for filename, cores in files.items():
    d = []
    s_thread = []
    e_thread = []
    s_omp = []
    e_omp = []

    with open(filename, "r") as f:
        reader = csv.DictReader(f)
        for row in reader:
            depth = int(row["Depth"])
            t_seq = float(row["Search"])
            t_thread = float(row["ThreadSearch"])
            t_omp = float(row["OMPSearch"])

            # Speedup
            sp_thread = t_seq / t_thread
            sp_omp = t_seq / t_omp

            # Efficiency
            ef_thread = sp_thread / cores
            ef_omp = sp_omp / cores

            d.append(depth)
            s_thread.append(sp_thread)
            e_thread.append(ef_thread)
            s_omp.append(sp_omp)
            e_omp.append(ef_omp)

    depths[cores] = d
    speedup[cores] = s_thread
    efficiency[cores] = e_thread
    speedup_omp[cores] = s_omp
    efficiency_omp[cores] = e_omp

plt.figure()
for threads in files.values():
    plt.plot(depths[threads], speedup[threads],
             label=f"ThreadSearch ({threads})")

for threads in files.values():
    plt.plot(depths[threads], speedup_omp[threads],
             linestyle="--",
             label=f"OMPSearch ({threads})")

plt.xlabel("Depth")
plt.ylabel("Speedup")
plt.title("OLD (Speedup vs Depth)")
plt.grid(True)
plt.legend(loc="upper right")
plt.savefig("old_speedup.png", dpi=300)
plt.close()

plt.figure()
for threads in files.values():
    plt.plot(depths[threads], efficiency[threads],
             label=f"ThreadSearch ({threads})")

for threads in files.values():
    plt.plot(depths[threads], efficiency_omp[threads],
             linestyle="--",
             label=f"OMPSearch ({threads})")

plt.xlabel("Depth")
plt.ylabel("Efficiency")
plt.title("OLD (Efficiency vs Depth)")
plt.grid(True)
plt.legend(
    loc="best",
    fontsize=8,
    framealpha=0.7,
    borderpad=0.2,
    labelspacing=0.2,
    handlelength=1.4,
)
plt.tight_layout(rect=[0, 0, 0.8, 1])
plt.savefig("old_efficiency.png", dpi=300)
plt.close()
