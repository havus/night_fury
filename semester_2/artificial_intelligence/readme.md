

p | q | (p -> q) | (p -> q) ^ p | ((p -> q) ^ p) -> q
--------------------------------------------------
b | b | b        | b            | b
b | s | s        | s            | b
s | b | b        | s            | b
s | s | b        | s            | b

Tautologi adalah yg bernilai benar semua
Kontradiksi adalah yg bernilai salah semua
Kontingensi adalah yg tidak selalu bernilai benar atau salah

((p -> q) ^ p) -> q adalah Tautologi

\
------------------------------------------------------------------------
saya ingin bertanya, apakah ada contoh cara yang digunakan untuk menangani strategi pencarian ini? dan apakah strategi ini lebih mudah dipahami dibandingkan dengan strategi pencarian uninformed?
mohon bantuannya. sebutkan sumber jawaban Anda.
terimakasih


Informed Search sering disebut juga dengan Heuristic Search. Pencarian dengan algoritma ini menggunakan knowledge yang spesifik kepada permasalahan yang dihadapi disamping dari definisi masalahnya itu sendiri. Metode ini mampu menemukan solusi secara lebih efisien daripada yang bisa dilakukan pada metode uninformed strategy.
src: https://socs.binus.ac.id/2013/04/23/uninformed-search-dan-informed-search/
\
------------------------------------------------------------------------

strategi pencarian uninformed adalah pencarian tanpa informasi atau pencarian buta.
pertanyaan :
apakah strategi pencarian ini membutuhkan waktu yang relatif lama untuk melakukan pencariannya? dan adakah salah satu contoh penggunaannya? sebutkan sumber dari jawaban yang Anda post.
terimakasih

apakah strategi pencarian ini membutuhkan waktu yang relatif lama untuk melakukan pencariannya?
uninformed search menghabiskan lebih banyak waktu dan biaya karena tidak memiliki petunjuk tentang solusi dibandingkan dengan informed search.
adakah salah satu contoh penggunaannya?
Breadth-first search adalah strategi yang optimal karena selalu melakukan ekspansi node yang berada dicabang berikutnya
src: LN-1
\
------------------------------------------------------------------------

Penalaran Maju dan Mundur
Penalaran maju (forward chaining) adalah penalaran yang berdasarkan pada data yang sudah diketahui sebelumnya untuk mencapai pada kesimpulan. Sedangkan untuk penalaran mundur, bekerja secara mundur untuk membuktikan kesimpulan benar. Berikan contoh dari penerapan penalaran di atas. 

contoh penalaran maju:
ketika seseorang ingin memasak burger, dia perlu membeli daging, roti dan sayur.
contoh penalaran mundur:
ketika seorang CEO perusahaan menyadari arus kas nya buruk, dia harus membuka cashflow bulan2 sebelumnya dan menyimpulkan penyebab kenapa cashflow memburuk
\
------------------------------------------------------------------------

Modus Ponens
Jika saya menyapu rumah (P), maka ibu akan senang (Q).
Saya menyapu rumah (P).
Maka, kesimpulannya ibu senang (Q).
Kalimat di atas merupakan contoh dari modus ponens. Tolong dibuktikan apakah benar kesimpulan dari kalimat di atas. Jelaskan dari pembuktian yang Anda berikan.

p | q | (p -> q) | (p -> q) ^ p | ((p -> q) ^ p) -> q
--------------------------------------------------
b | b | b | b | b
b | s | s | s | b
s | b | b | s | b
s | s | b | s | b

Tautologi adalah yg bernilai benar semua
Kontradiksi adalah yg bernilai salah semua
Kontingensi adalah yg tidak selalu bernilai benar atau salah

((p -> q) ^ p) -> q adalah Tautologi
\
------------------------------------------------------------------------

First Order Logic

selamat sore pak izin menjawab:
Ide dari algoritma penalaran maju (forward chaining) dimulai dari modes ponen
sedangkan rangkaian mundur (backward chaining) dengan proses penalaran modus ponen sehingga dicapai suatu tujuan, membuktikan kesimpulan yang diperoleh dengan mencari semua fakta yang mendukungnya berdasarkan permasalahan pada penalaran maju
\
------------------------------------------------------------------------

What is the interpretation for:

King(Richard) ᴠ King(John)
¬Brother (LeftLeg(Richard), John)
ⱯxⱯyBrother(x,y) → Sibling(x,y)
In(Paris, France) Λ In(Marseilles, France)
Ɐc Country(c) Λ Border(c, Ecuador) → In(c, SouthAmerica)
ⱻCountry(c) Λ Border(c, Spain) Λ Border(c, Italy)
Bagainama Anda membaca kalimat di atas. Tuliskan jawaban Anda. 

1. king richard atau king john
2. left leg Richard, bukan brother john
3. setiap x adalah sudara lk dari Y, maka x sibling y
4. paris di prancis dan Marseilles di prancis
5. untuk setiap c, jika c adalah negara perbatasan ekuador , maka c di dalam amerika selatan
6. beberapa negara berbatasan dengan spain dan berbatasan dengan italy

\
------------------------------------------------------------------------

Semantic Network
Semantic Network memiliki keuntungan dan kerugian. Mohon dijelaskan ya. Terima kasih.

Kelebihan
- lebih alami daripada representasi logis;
- memungkinkan penggunaan algoritma inferensi yang efektif (algoritma grafis)
- sederhana dan dapat dengan mudah diimplementasikan dan dipahami.
- dapat digunakan sebagai aplikasi koneksi yang khas di antara berbagai bidang pengetahuan, misalnya di antara ilmu komputer dan antropologi.
- memungkinkan pendekatan sederhana untuk menyelidiki ruang masalah.
- memberikan pendekatan untuk membuat cabang-cabang komponen terkait
- dicirikan oleh kecukupan kognitif yang lebih besar dibandingkan dengan formalisme berbasis logika.
- memiliki ekspresi yang lebih besar dibandingkan dengan logika.

Kekurangan
- Tidak ada definisi standar untuk nama tautan
- tidak cerdas, bergantung pada penciptanya
- tidak sama dalam fungsi atau bentuk, kebingungan dalam tautan yang menegaskan hubungan dan tautan struktural
- node yang tidak dibedakan yang mewakili kelas dan yang mewakili objek individu
- tautan pada objek hanya mewakili relasi biner
- negasi dan disjungsi dan pengetahuan taksonomi umum tidak mudah diungkapkan.

\
------------------------------------------------------------------------

Knowledge & Intelligence
Apa yang Anda ketahui terkait dengan hubungan (relation) diantara Knowledge dengan intelligence. Jelaskan lagi ya. Terima kasih.

pengetahuan adalah fakta, kebenaran atau informasi yang diperoleh melalui pengalaman atau pembelajaran disebut posteriori, atau melalui introspeksi diebut priori. tidak dibatasi pada deskripsi, hipotesis, konsep, teori, prinsip dan prosedur yang secara Probabilitas Bayesian adalah benar atau berguna
kecerdasan adalah kemampuan untuk memperoleh pengetahuan dan keterampilan serta kemampuan untuk menggunakannya. Ini mencakup kemampuan pemahaman, logika, abstraksi, pengetahuan emosional, pembelajaran, kesadaran diri, penalaran, kreativitas, perencanaan, pemecahan masalah dan pemikiran kritis.

\
------------------------------------------------------------------------

Uncertainty
Menurut kalian data yang seperti apa yang merupakan/disebut sebagai sumber ketidakpastian. Tolong dijelaskan dan sebutkan sumber jawaban Anda.

- sistematik
merupakan ketidakpastian yang disebabkan karena alat ukur atau kondisi-kondisi saat pengukuran. Sebagai contoh adalah ketidakpastian alat, kesalahan penunjuk skala, waktu pengukuran yang kurang tepat, dll.
- random (acak)
merupakan ketidakpastian yang berasal dari gejala acak yang tidak dapat dikendalikan. Contohnya adalah fluktuasi pada besaran listrik, gerak acak molekul udara, getaran landasan, dll.
- pengamatan
berasal dari kurangnya keterampilan pengamat saat melakukan pengukuran. Sebagai contoh adalah pengaturan alat yang kurang tepat, pembacaan skala yang tidak sesuai, dll.
src: https://roboguru.ruangguru.com/forum/sebut-dan-jelaskan-tiga-sumber-ketidakpastian-pengukuran-_FRM-J70EAN9U?action=login&_tracker=forum_detail_lock

\
------------------------------------------------------------------------

Probability
Setelah Anda melakukan pemeriksaan medical checkup, Dokter memiliki kabar buruk dan kabar baik. Berita buruknya adalah hasil tes, Anda dinyatakan positif mengidap penyakit serius dan bahwa tes tersebut 99% akurat. Kabar baiknya adalah bahwa ini adalah penyakit langka, hanya menyerang 1 dari 10.000 orang seusia Anda. Mengapa kabar baiknya bahwa penyakit ini jarang terjadi? Seberapa besar kemungkinan Anda benar-benar mengidap penyakit tersebut?

A1: anda mengidap penyakit serius
A2. anda tidak mengidap penyakit serius
B: diprediksi penyakit langka ini hanya menyerang 1 dari 10.000

P(A1): 99/100 = 0.99
P(A2): 1/100 = 0.01
P(B | A1): 0.01 [jika sakit, maka jurnal penyakit langka ini hanya menyerang 1 dari 10.000 1% benar]
P(B | A2): 0.99 [jika tidak sakit, maka jurnal penyakit langka ini hanya menyerang 1 dari 10.000 99% benar]

P(A1 | B) = (0.99 0.01) / ((0.99 0.01) + 0.01 * 0.99) = 0.5 (kemungkinan positif)

\
------------------------------------------------------------------------

Variable
menurut kalian apa itu variable continuous dan discrete, jelaskan persamaan dan perbedaannya ya

data diskrit: data berupa angka yang hanya menampilkan angka dan dihitung dalam jumlah bilangan bulat. Informasi dalam data diskrit berisi sejumlah nilai atau angka yang terbatas dan tidak dapat dipecah menjadi lebih presisi, seperti angka yang muncul dalam dadu yang hanya dapat memunculkan angka 1 sampai dengan 6.

data kontinu: data yang dapat mengambil nilai numerik apapun, biasanya dalam batas tertentu, dan dapat dibagi menjadi nilai yang lebih presisi. Kemudian, data kontinu sendiri menggambarkan satu set pengamatan yang tidak terputus dan dapat diukur dengan skala. (contoh grafik suhu, nilai mata uang, dll)

\
------------------------------------------------------------------------

Jaringan Bayesian
adalah grafik asiklik berarah dengan beberapa parameter numerik yang melekat pada masing-masing node, salah satu cara untuk mendefinisikan apa arti semantic jaringan bayes adalah menentukan cara di mana ia mewakili distribusi bersama secara spesifik untuk semua variabel.
pertanyaan : apakah tujuan penggunaan jaringan bayesian?

digunakan untuk mewakili dependensi antar variabel dan distribusi full joint probabilitas. Dalam banyak kasus jaringan Bayesian dapat melakukannya dengan sangat ringkas dengan menggunakan notasi grafis sederhana.

Metode Bayesian Network merupakan metode yang baik di dalam mesin pembelajaran berdasarkan data training, dengan menggunakan probabilitas bersyarat sebagai dasarnya. Bayesian Network (BN) atau jaringan bayes juga dikenal sebagai jaringan kepercayaan dari jaringan bayes yang pendek dan masih merupakan probabilistic graphical model (PGM) dengan edge berarah yang digunakan untuk merepresentasikan pengetahuan tentang hubungan ketergantungan atau kebebasan diantara variabel-variabel domain persoalan yang dimodelkan. Pengetahuan tersebut direpresentasikan secara kualitatif menggunakan struktur graf dan secara kuantitatif menggunakan parameter-parameter numerik

src: LN_06 dan http://repository.uin-suska.ac.id/19033/7/7.%20BAB%20II.pdf

\
------------------------------------------------------------------------

Supervised vs Unsupervised Learning
Supervised learning dan Unsupervised learning merupakan dua tipe utama dari metode Machine Learning. Apakah perbedaan dari kedua metode tersebut? Jelaskanlah.

supervised learning:
- algoritma dilatih terlebih dulu baru bisa bekerja
- mengenali data dari label khusus yang telah diberikan sebelumnya
- kegunaan: mengumpulkan atau memproduksi output data dari pengalaman yang sudah pernah terjadi

unsupervised learning:
- dirancang untuk bisa langsung bekerja walaupun tanpa dilatih terlebih dulu
- mengenali data secara real-time begitu data disajikan
- kegunaan: prediksi waktu pada peta digital, untuk mencari rute menuju lokasi tertentu, sistem akan mencantumkan prediksi waktu tempuh. Padahal, belum pernah berkendara ke lokasi tersebut. (unlabled)

\
------------------------------------------------------------------------

Decision Tree
Decision Tree adalah teknik pembelajaran Terbimbing (Supervised Learning) yang dapat digunakan untuk masalah klasifikasi dan Regresi, tetapi sebagian besar lebih disukai untuk menyelesaikan masalah Klasifikasi. Pada pohon keputusan terdapat dua simpul yaitu simpul keputusan (Decision Node) dan simpul daun (Leave Node). Apa yang Anda pahami tentang Leave Node dan Decision Node?


decision node adalah sub tree, parent dari leaf node, dimulai dengan satu node atau simpul. kemudian, node tersebut bercabang untuk menyatakan pilihan-pilihan yang ada
leaf node adalah cabang (yg tidak memiliki cabang lagi) dari decision node. kemungkinan hasil atas setiap tindakan

\
------------------------------------------------------------------------

Explanation Based Leaning
Pembelajaran berbasis penjelasan yang merupakan metode untuk mengekstraksi aturan umum dari pengamatan individu. Pertanyaannya bagaimana menurut Anda proses Explanation Based Learning bekerja?

- membuat pembukti bahwa predikat tujuan berlaku untuk contoh menggunakan pengetahuan yang tersedia sebelumnya.
- membuat pohon bukti umum untuk variabilisasi tujuan menggunakan langkah inferensi yang sama seperti pada bukti awal.
- membuat aturan baru yang sisi kirinya terdiri dari daun pohon bukti dan sisi kanannya adalah tujuan variabilisasi (setelah menerapkan binding yang diperlukan dari bukti umum).
- hilangkan kondisi apapun dari sisi kiri yang benar terlepas dari nilai variabel pada tujuannya

EBL menerima 4 macam input:
1. goal concept
2. training example
3. operational criterion (facts)
4. domain theory
# use problem solver to justify, using the rules, the goals in terms of of fact
# generalization - generalize the justification as much as possible

EBL memiliki 2 step:
1. explanation: the domain theory is used to remove all unimportant aspects of the training example with respect to the goal concept
2. generalization: the explanation is generalize as far as possible while describing the goal concept

\
------------------------------------------------------------------------

Inductive Logic Programming
Pemrograman logika induktif (ILP) adalah metode yang menggabungkan metode
induktif dengan FOL. Apa saja alasan ILP banyak digunakan?

kelebihan ILP:
1. kemampuan untuk menghasilkan hipotesis dalam bentuk aturan logika FOL (First-Order Logic), yang lebih mudah dipahami dan dipelajari oleh manusia.
2. kemampuan untuk mengatasi masalah dengan jumlah data yang besar, sehingga dapat menghasilkan aturan logika yang lebih baik dan akurat dalam waktu yang lebih singkat.
3. kemampuan untuk menghasilkan aturan logika yang lebih spesifik dan kompleks daripada teknik pembelajaran mesin tradisional, seperti decision tree atau neural network.
4. kemampuan untuk belajar dari data yang tidak lengkap atau tidak terstruktur, sehingga dapat digunakan dalam berbagai bidang, seperti pemrosesan bahasa alami, pengenalan objek, dan bioinformatika.

kekurangan:
1. sulitnya memahami dan menafsirkan aturan logika yang dihasilkan
2. kecenderungan untuk overfitting (terlalu fokus pada data latih dan tidak generalisasi dengan baik)

\
------------------------------------------------------------------------

Teknik yang Digunakan dalam NLP
Menurut Textmetrics, NLP digunakan untuk mengukur sentimen dan menentukan bagian mana dari bahasa manusia yang penting. Sistem NLP menginterpretasikan bahasa dalam 6 level. Jelaskan. Terima kasih.

1. Phonetics and phonology: pada level ini, teks yang diberikan dipecah menjadi token atau unit terkecil yang memiliki arti dalam bahasa. Misalnya, kata, tanda baca, angka, dan lain-lain.
2. Morphology: pada level ini, setiap token yang ditemukan dianalisis bentuk dan maknanya. Contohnya, kata kerja dapat dianalisis menjadi kata dasar (lematisasi), konjugasi (tense), dan partikel lainnya.
3. Syntax: pada level ini, hubungan antara token yang satu dengan yang lain dianalisis untuk membentuk struktur kalimat yang benar. Contohnya, mengenali subjek dan predikat, serta hubungan antara keduanya.
4. Semantics: pada level ini, makna kalimat dianalisis dengan mempertimbangkan makna dari setiap token yang digunakan dan cara token tersebut disusun. Dalam level ini, sistem NLP mencoba memahami maksud dari kalimat yang diberikan.
5. Pragmatics: pada level ini, sistem NLP mencoba memahami konteks dari kalimat yang diberikan. Sistem mencoba memahami apa yang ingin diungkapkan oleh pembicara dan bagaimana konteks penggunaan kata dan kalimat mempengaruhi makna yang disampaikan.
6. Discourse: pada level ini, sistem NLP mencoba memahami tujuan dan aksi yang ingin dicapai oleh pembicara. Misalnya, apakah pembicara ingin meminta maaf, memuji, atau memberikan perintah.

\
------------------------------------------------------------------------

Manfaat NLP
Teknologi ini telah membantu perusahaan/organisasi dari banyak industri untuk memberikan keuntungan terhadap bisnisnya. Menurut Anda manfaat apa yang diperoleh perusahaan saat menggunakan teknologi NLP?

1. Autocorrect pada surat2 perusahaan
2. Filter Email
3. Mesin Penerjemah
4. Chatbot untuk menjadi layer sebelum customer service
5. Voice Assistant

src: https://bitlabs.id/blog/natural-language-processing-adalah

\
------------------------------------------------------------------------

thread 1
Pembentukan citra dari sensor agen dapat dilihat dari beberapa proses, sebut dan jelaskan proses tersebut.

- Acquisition atau Pengambilan Gambar: tahapan ini merupakan proses dimana sensor menerima sinyal dari lingkungan sekitar melalui lensa kamera. sinyal ini kemudian diterjemahkan menjadi data digital yang akan diproses lebih lanjut

- Preprocessing atau Pra-pemrosesan: tahapan ini dilakukan untuk memperbaiki kualitas gambar dari data digital yang diperoleh dari tahapan acquisition. preprocessing bisa meliputi pembersihan noise, penerapan filter untuk meningkatkan kualitas gambar, dan lain sebagainya

- Segmentation atau Segmentasi: tahapan ini bertujuan untuk memisahkan objek atau bagian gambar yang akan dianalisis dari bagian gambar yang tidak diperlukan, dengan teknik seperti thresholding, clustering, dan lain-lain

- Feature extraction atau Ekstraksi Fitur: tahapan ini merupakan proses untuk mengambil informasi yang relevan dari bagian gambar yang telah dipisahkan pada tahapan segmentation. proses ini melibatkan teknik pengolahan citra seperti edge detection, corner detection, dan lain sebagainya

- Recognition atau Pengenalan: tahapan ini bertujuan untuk mengidentifikasi objek atau fitur yang telah diekstraksi pada tahapan sebelumnya. hal ini dapat dilakukan dengan menggunakan teknik pengenalan pola seperti klasifikasi, clustering, dan lain-lain

\
------------------------------------------------------------------------

thread 2
Beberapa efek dapat memindahkan fitur di sekitar gambar objek, sebut dan jelaskan kembali.

foreshortening: terjadi ketika objek dihasilkan dalam sebuah gambar 2D dengan sudut pandang yang membuat seolah-olah objek tersebut menjadi pendek atau memendek. disebabkan karena salah satu bagian objek tersebut terlihat lebih kecil dari yang seharusnya, yang dapat memindahkan fitur objek ke arah yang salah
aspect: Efek ini terjadi ketika objek yang digambar memiliki perbedaan ukuran proporsi yang tidak sesuai dengan yang seharusnya. dapat memindahkan fitur objek ke arah yang salah, seperti memanjangkan atau memendekkan bagian-bagian tertentu dari objek tersebut
occlusion: efek ini terjadi ketika bagian dari objek tertutup oleh bagian lain dari objek tersebut atau oleh objek lain di sekitarnya. dapat memindahkan fitur objek ke arah yang salah, seperti membuat objek tersebut terlihat lebih kecil dari ukuran sebenarnya karena bagian-bagian tertentu tersembunyi
deformation: efek ini terjadi ketika objek yang digambar mengalami deformasi atau distorsi, seperti pada gambar yang diambil dari sudut pandang yang tidak biasa atau pada gambar dengan resolusi yang rendah. hal ini dapat memindahkan fitur objek ke arah yang salah, seperti membuat objek tersebut terlihat berbeda atau tidak teratur

