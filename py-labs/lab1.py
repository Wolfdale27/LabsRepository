import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import savgol_filter

file_path = '/Users/wolfdale27/Downloads/ECG-normal-in-txt/ECG-normal.txt'
signals = {'#I': [], '#II': [], '#III': [], '#avR': [], '#avL': [], '#avF': []}
fs = None
samples_count = None

with open(file_path, 'r', encoding='cp1251') as file:
    lines = file.readlines()

# Поиск частоты дискретизации и количества сэмплов
for i, line in enumerate(lines):
    if 'Частота дискретизации' in line:
        fs = int(lines[i + 1].strip())
    elif 'Количество экспортированных сэмплов' in line:
        samples_count = int(lines[i + 1].strip())
    for lead in signals.keys():
        if line.startswith(lead):
            signal_line = lines[i + 1].strip()
            if signal_line:
                signals[lead] = [int(x) for x in signal_line.split(';') if x.isdigit()]

# Приведение всех сигналов к одинаковой длине (samples_count)
for lead, signal in signals.items():
    if len(signal) > samples_count:
        signals[lead] = signal[:samples_count]
    elif len(signal) < samples_count:
        signals[lead] = np.pad(signal, (0, samples_count - len(signal)), 'constant')

# Построение графиков для первых 3 секунд данных
plt.figure(figsize=(14, 10))
time = np.linspace(0, 3, int(fs * 3))  # Ось времени для первых 3 секунд

bg_color = '#f9e6e6'  
major_grid_color = '#e3bcbc'  
minor_grid_color = '#f7d9d9'  

for i, (lead, signal) in enumerate(signals.items(), start=1):
    signal_segment = signal[:int(fs * 3)]  
    smoothed_signal = savgol_filter(signal_segment, 51, 3)  
    
    ax = plt.subplot(3, 2, i)
    ax.set_facecolor(bg_color) 
    ax.plot(time, smoothed_signal, color='black', linewidth=1, label=f'ECG {lead}')    
    ax.grid(which='major', color=major_grid_color, linewidth=0.8)  
    ax.grid(which='minor', color=minor_grid_color, linewidth=0.4)  
    ax.minorticks_on() 
    plt.title(f'Кардиограмма (сигнал отведения {lead})')
    plt.xlabel('Время (сек)')
    plt.ylabel('Потенциал (мкВ)')
    plt.legend()
plt.tight_layout()
plt.show()
