import numpy as np
from scipy.stats import t

# Dataset
pulse1 = [64, 58, 62, 66, 64, 74, 84, 68, 62, 76, 90, 80, 92, 68, 60, 62, 66, 70, 68, 72, 70, 74, 66, 70, 96, 62, 78, 82, 100, 68, 96, 78, 88, 62, 80, 62, 60, 72, 62, 76, 68]
pulse2 = [88, 70, 76, 78, 80, 84, 84, 72, 75, 118, 94, 96, 84, 76, 76, 58, 82, 72, 76, 80, 106, 76, 102, 94, 140, 100, 104, 100, 115, 112, 116, 118, 110, 98, 128, 62, 62, 74, 66, 76, 66]

# Menghitung selisih
selisih = np.array(pulse1) - np.array(pulse2)

# Menghitung t-statistik dan p-value
n = len(selisih)
mean_selisih = np.mean(selisih)
std_selisih = np.std(selisih, ddof=1)
t_statistic = (mean_selisih - 0) / (std_selisih / np.sqrt(n))
p_value = t.sf(np.abs(t_statistic), df=n-1)  # one-tailed test

# Menampilkan hasil
alpha = 0.05
if p_value < alpha:
    print("Tolak H0, nilai rata-rata Pulse 1 lebih besar daripada nilai rata-rata Pulse 2")
else:
    print("Gagal menolak H0, tidak ada cukup bukti bahwa nilai rata-rata Pulse 1 lebih besar daripada nilai rata-rata Pulse 2")

print("t-statistik:", t_statistic)
print("p-value:", p_value)
