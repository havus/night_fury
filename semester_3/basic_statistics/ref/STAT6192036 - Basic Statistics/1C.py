import pandas as pd
import matplotlib.pyplot as plt
from openpyxl import Workbook
from openpyxl.drawing.image import Image
import os

# Membuat DataFrame dari dataset
data = {
    'age': [39, 50, 38, 53, 28, 37, 49, 52, 31, 42, 37, 30, 23, 32, 40, 34, 25, 32, 38, 43, 40, 54, 35, 43, 59, 56, 19, 54, 39, 49, 23, 20, 45, 30, 22, 48, 21, 19, 31, 48, 31, 53, 24, 49, 25, 57, 53, 44, 41, 29, 25, 18, 47, 50, 47, 43, 46, 35, 41, 30, 30, 32, 48, 42, 29, 36, 28, 53, 49, 25, 19, 31, 29, 23, 79, 27, 40, 67, 18, 31, 18, 52, 46, 59, 44, 53, 49, 33, 30, 43, 57, 37, 28, 30, 34, 29, 48, 37, 48, 32, 76, 44, 47, 20, 29, 32, 17, 30, 31, 42, 24, 38, 56, 28, 36, 53, 56, 49, 55, 22, 21, 40, 30, 29, 19, 47, 20],
    'workclass': ['State-gov', 'Self-emp-not-inc', 'Private', 'Private', 'Private', 'Private', 'Private', 'Self-emp-not-inc', 'Private', 'Private', 'Private', 'State-gov', 'Private', 'Private', 'Private', 'Private', 'Self-emp-not-inc', 'Private', 'Private', 'Self-emp-not-inc', 'Private', 'Private', 'Federal-gov', 'Private', 'Private', 'Local-gov', 'Private', '?', 'Private', 'Private', 'Local-gov', 'Private', 'Private', 'Federal-gov', 'State-gov', 'Private', 'Private', 'Private', 'Private', 'Self-emp-not-inc', 'Private', 'Self-emp-not-inc', 'Private', 'Private', 'Private', 'Federal-gov', 'Private', 'Private', 'State-gov', 'Private', 'Private', 'Private', 'Private', 'Federal-gov', 'Self-emp-inc', 'Private', 'Private', 'Private', 'Private', 'Private', 'Private', '?', 'Private', 'Private', 'Private', 'Private', 'Private', 'Private', 'Self-emp-inc', '?', 'Private', 'Private', 'Self-emp-not-inc', 'Private', 'Private', 'Private', 'Private', '?', 'Private', 'Local-gov', 'Private', 'Private', 'Private', 'Private', 'Private', 'Private', 'Local-gov', 'Private', 'Private', 'Federal-gov', 'Private', 'Private', 'Private', 'Private', 'Local-gov', 'Local-gov', 'Self-emp-not-inc', 'Private', 'Private', 'Federal-gov', 'Private', 'Private', 'Self-emp-not-inc', 'Private', 'Private', 'Self-emp-inc', '?', 'Private', 'Local-gov', 'Private', 'Private', 'Private', 'Self-emp-not-inc', 'Private', 'Private', 'Private', 'Self-emp-inc', 'Local-gov', 'Private', 'Private', 'Private', 'Private', 'Private', 'State-gov', 'Private', 'Private', 'Private'],
    'race': ['White', 'White', 'White', 'Black', 'Black', 'White', 'Black', 'White', 'White', 'White', 'Black', 'sian-Pac-Island', 'White', 'Black', 'sian-Pac-Island', 'mer-Indian-Eski', 'White', 'White', 'White', 'White', 'White', 'Black', 'Black', 'White', 'White', 'White', 'White', 'sian-Pac-Island', 'White', 'White', 'White', 'Black', 'White', 'White', 'Black', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'Black', 'White', 'White', 'White', 'White', 'Other', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'Black', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'Black', 'sian-Pac-Island', 'White', 'White', 'White', 'White', 'White', 'Black', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'White', 'Black', 'White', 'White', 'White', 'White', 'Black', 'White', 'Black', 'White', 'White'],
    'sex': ['Male', 'Male', 'Male', 'Male', 'Female', 'Female', 'Female', 'Male', 'Female', 'Male', 'Male', 'Male', 'Female', 'Male', 'Male', 'Male', 'Male', 'Male', 'Male', 'Female', 'Male', 'Female', 'Male', 'Male', 'Female', 'Male', 'Male', 'Male', 'Male', 'Male', 'Male', 'Male', 'Male', 'Male', 'Male', 'Male', 'Male', 'Female', 'Male', 'Male', 'Male', 'Male', 'Male', 'Female', 'Male', 'Male', 'Male', 'Female', 'Male', 'Male', 'Female', 'Female', 'Female', 'Male', 'Male', 'Male', 'Male', 'Male', 'Male', 'Male', 'Male', 'Male', 'Male', 'Male', 'Male', 'Male', 'Female', 'Female', 'Male', 'Male', 'Male', 'Female', 'Male', 'Male', 'Male', 'Male', 'Male', 'Male', 'Female', 'Male', 'Male', 'Male', 'Female', 'Male', 'Female', 'Female', 'Male', 'Male', 'Male', 'Female', 'Male', 'Female', 'Female', 'Female', 'Male', 'Male', 'Male', 'Male', 'Female', 'Male', 'Male', 'Male', 'Female', 'Female', 'Male', 'Male', 'Female', 'Male', 'Female', 'Male', 'Male', 'Male', 'Male', 'Female', 'Female', 'Male', 'Male', 'Male', 'Male', 'Male', 'Female', 'Male', 'Male', 'Male', 'Male', 'Female', 'Female'],
    'hours-per-week': [40, 13, 40, 40, 40, 40, 16, 45, 50, 40, 80, 40, 30, 50, 40, 45, 35, 40, 50, 45, 60, 20, 40, 40, 40, 40, 40, 60, 80, 40, 52, 44, 40, 40, 15, 40, 40, 25, 38, 40, 43, 40, 50, 40, 35, 40, 38, 40, 40, 43, 40, 30, 60, 55, 60, 40, 40, 40, 48, 40, 40, 40, 40, 45, 58, 40, 40, 40, 50, 40, 32, 40, 70, 40, 20, 40, 40, 2, 22, 40, 30, 40, 40, 48, 40, 35, 40, 50, 40, 50, 40, 40, 25, 35, 40, 50, 60, 48, 40, 40, 40, 60, 50, 40, 40, 40, 32, 40, 40, 40, 40, 40, 50, 25, 40, 50, 50, 40, 56, 41, 40, 60, 40, 50, 35, 40, 28],
    'native-country': ['United-States', 'United-States', 'United-States', 'United-States', 'Cuba', 'United-States', 'Jamaica', 'United-States', 'United-States', 'United-States', 'United-States', 'India', 'United-States', 'United-States', '?', 'Mexico', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'South', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'Puerto-Rico', 'United-States', 'United-States', '?', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', '?', 'Honduras', 'United-States', 'United-States', 'United-States', 'Mexico', 'Puerto-Rico', 'United-States', 'United-States', 'United-States', '?', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'Mexico', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'Cuba', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', '?', 'United-States', 'United-States', 'United-States', 'United-States', 'England', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'Canada', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'United-States', 'Germany', 'United-States', 'United-States', 'United-States', 'United-States'],
    'salary': ['<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '>50K', '>50K', '>50K', '>50K', '>50K', '<=50K', '<=50K', '>50K', '<=50K', '<=50K', '<=50K', '<=50K', '>50K', '>50K', '<=50K', '<=50K', '<=50K', '<=50K', '>50K', '<=50K', '>50K', '<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '>50k', '<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '>50K', '<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '>50K', '>50K', '<=50K', '>50K', '<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '>50K', '<=50K', '<=50K', '<=50K', '>50K', '>50K', '<=50K', '<=50K', '<=50K', '>50K', '<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '>50K', '<=50K', '>50K', '<=50K', '<=50K', '>50K', '<=50K', '<=50K', '<=50K', '<=50K', '>50K', '<=50K', '>50K', '>50K', '<=50K', '<=50K', '>50K', '>50K', '<=50K', '<=50K', '<=50K', '>50K', '<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '>50K', '>50K', '<=50K', '<=50K', '<=50K', '<=50K', '>50K', '<=50K', '<=50K', '<=50K', '<=50K', '<=50K', '>50K', '<=50K', '>50K', '<=50K']
}

df = pd.DataFrame(data)

# Membuat direktori untuk menyimpan file Excel
directory = 'dataset_visualizations'
if not os.path.exists(directory):
    os.makedirs(directory)

# Membuat visualisasi dan menyimpannya dalam file Excel
wb = Workbook()
ws = wb.active

# Membuat visualisasi untuk setiap variabel
for i, col in enumerate(df.columns):
    plt.figure(figsize=(10, 6))
    if df[col].dtype == 'object':
        df[col].value_counts().plot(kind='bar')
    else:
        df[col].plot(kind='hist')
    plt.title(col)
    plt.xlabel(col)
    plt.ylabel('Count')
    plt.tight_layout()

    # Menyimpan visualisasi dalam file gambar
    image_path = os.path.join(directory, f'{col}_visualization.png')
    plt.savefig(image_path)
    plt.close()

    # Memasukkan gambar ke file Excel
    img = Image(image_path)
    ws.add_image(img, f'A{(i+1)*12}')

# Menyimpan file Excel
excel_file = 'dataset_visualizations.xlsx'
wb.save(excel_file)
wb.close()

print(f"Visualisasi dataset telah disimpan dalam file {excel_file} dan gambar-gambar terkait tersedia di folder {directory}.")
