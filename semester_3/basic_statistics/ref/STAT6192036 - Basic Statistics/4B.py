import pandas as pd
import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score

data = {
    'Weight': [66, 72, 73.5, 73, 69, 73, 72, 74, 72, 71, 74, 72, 70, 67, 71, 72, 69, 73, 74, 66, 71, 70, 70, 75, 61, 66, 68, 68, 63, 70, 68, 69, 69, 62.75, 68, 74, 71, 69, 70, 72, 67, 69, 73, 73, 71, 68, 69.5, 73, 75, 66, 69, 66, 73, 68, 74, 73.5, 70, 67, 72, 75, 68, 69, 71.5, 71, 72, 69, 67, 68, 66, 65.5, 66, 62, 62, 63, 67, 65, 66, 65, 65, 65, 64, 67, 69, 68, 63, 62, 63, 64, 68, 62, 67, 61.75],  # Isi dengan data berat
    'Height': [140, 145, 160, 190, 155, 165, 150, 190, 195, 138, 160, 155, 153, 145, 170, 175, 175, 170, 180, 135, 170, 157, 130, 185, 140, 120, 130, 138, 121, 125, 116, 145, 150, 112, 125, 190, 155, 170, 155, 215, 150, 145, 155, 155, 150, 155, 150, 180, 160, 135, 160, 130, 155, 150, 148, 155, 150, 140, 180, 190, 145, 150, 164, 140, 142, 136, 123, 155, 130, 120, 130, 131, 120, 118, 125, 135, 125, 118, 122, 115, 102, 115, 150, 110, 116, 108, 95, 125, 133, 110, 150, 108]  # Isi dengan data tinggi
}

df = pd.DataFrame(data)

correlation = df['Weight'].corr(df['Height'])
print("Korelasi antara berat dan tinggi:", correlation)

X = df[['Weight']]  # Memisahkan fitur berat sebagai variabel independen
y = df['Height']  # Variabel dependen

regression_model = LinearRegression()
regression_model.fit(X, y)

print("Koefisien:", regression_model.coef_)
print("Intercept:", regression_model.intercept_)

predicted_height = regression_model.predict(X)
r_squared = r2_score(y, predicted_height)
print("Koefisien Determinasi (R-squared):", r_squared)
