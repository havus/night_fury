
sample csv
user_id,name,usage_kuota
1092,Dragon Lee,1000
817,Anne Hamington,5000

create VAR data = []
create VAR result = []

READ file .csv
LOOP line UNTIL EOF
  NEXT IF first linen

  create VAR temp = split string in line by separator
  add temp to data
ENDLOOP

LOOP data with index i
  create VAR total_usage = data[i][2]
  create VAR name = data[i][1]
  create VAR price_per_kuota = 0

  IF kuota_usage <= 1000
    price_per_kuota = 10
  ELSEIF kuota_usage > 1000 AND kuota_usage <= 10000
    price_per_kuota = 8
  ELSEIF > 10000
    price_per_kuota = 5
  ENDIF

  create VAR temp = { name: name, invoice_amount: total_usage * price_per_kuota }
  ADD temp to VAR result
ENDLOOP

print result

[
  [1092,Dragon Lee,1000],
  [817,Anne Hamington,5000]
]

problem definition
kuota_usage <= 1000 kbps -> Rp 10,00/kbps.
kuota_usage > 1000 kbps AND kuota_usage <= 10000 -> Rp 8,00/kbps.
kuota_usage > 10000 kbps -> Rp 5,00/kbps.

hierarki chart
main:
1. File Reader
2. Report
3. Calculator


