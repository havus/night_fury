
# Modules
src: https://blog.ub.ac.id/swhp/cohesion-vs-coupling/

## Cohesion
Cohesion, dimana dari modul penjualan terdapat fungsi-fungsi semisal menghitung harga pokok, menghitung diskon, menghitung keuntungan dll yang merupakan fungsi yang saling berkaitan pada modul penjualan. Sehingga ini yang disebut menganut prinsip High Cohesion.

| No  | Cohesion Level  | Cohesion attributes | Resultant module strength |
| :-: | :-------------- | :-----------------: | :-----------------------: |
| 1   | Coincidental    | Low Cohesion        | Weakest                   |
| 2   | Logical         | \|                  | \|                        |
| 3   | Temporal        | \|                  | \|                        |
| 4   | Procedural      | \|                  | \|                        |
| 5   | Comunicational  | \|                  | \|                        |
| 6   | Sequencial      | \|                  | \|                        |
| 7   | Functional      | High Cohesion       | Strongest                 |

note: semakin tinggi cohesion, maka semakin baik

## Coupling
Coupling, dari perangkat lunak yang membagi modul pembelian dengan penjualan terlihat bahwa pada kedua modul tersebut tidak memiliki keterikatan, andaikata dilakukan perubahan terhadap modul pembelian maka modul penjualan tidak akan bermaslaah. Sehingga ini yang disebut menganut prinsip Loose Coupling.


| No  | Coupling Level  | Coupling attributes | Resultant module design quality |
| :-: | :-------------- | :---------------:   | :-----------------------------: |
| 1   | Data            | Loose Coupling      | Best                            |
| 2   | Stamp           | \|                  | \|                              |
| 3   | Control         | \|                  | \|                              |
| 4   | External        | \|                  | \|                              |
| 5   | Common          | \|                  | \|                              |
| 6   | Content         | Tight coupling      | Poorest                         |

note: semakin rendah coupling, maka semakin baik


Loose Coupling, High Cohesion
