# Optimasi Alur Kerja CI/CD dengan Multistage Graph

Repositori ini dibuat untuk mengimplementasikan **Tugas Besar Algoritma & Pemrograman 2025-2026 Genap** ke C++. Program ini bertujuan untuk menyelesaikan permasalahan pencarian rute terpendek/termurah pada sebuah *Multistage Graph* menggunakan prinsip algoritma pencarian jalur (seperti Dijkstra / *Dynamic Programming*).

## Deskripsi Studi Kasus

Sebuah perusahaan teknologi menerapkan alur kerja otomatisasi *Continuous Integration & Continuous Deployment* (CI/CD) yang dibagi menjadi empat tahap utama:

**Tahap 1 (T1):** Code Analysis 
 
**Tahap 2 (T2):** Automated Testing 
 
**Tahap 3 (T3):** Security Scanning 
 
**Tahap 4 (T4):** Deployment 

Di setiap tahapan, terdapat beberapa pilihan layanan (*tools/worker*) dengan biaya operasional dan waktu eksekusi yang berbeda. Beberapa layanan juga memiliki ketergantungan atau bekerja lebih efisien jika digabungkan dengan layanan tertentu.

Tujuan utama dari program ini adalah **mencari rute layanan dari simpul asal (S) menuju simpul akhir (E) yang meminimalkan total Bobot (W)**. Nilai bobot (W) pada setiap *edge* telah dihitung menggunakan rumus:

> **$Bobot (W) = (Biaya \times 0,6) + (Waktu \times 0,4)$** 

## Fitur Program

Berdasarkan spesifikasi yang dibutuhkan, program ini dirancang untuk menerima *hardcoded-input* struktur graf dari alur CI/CD dan menghasilkan keluaran berupa:

**Total Bobot Minimal:** Menghitung dan menampilkan nilai total bobot kombinasi layanan yang paling efisien dari S ke E.
 
**Jejak Rute (Path):** Menampilkan rangkaian nama *node* (layanan) yang harus diambil dari awal hingga akhir (Contoh format: `S -> Ax -> ... -> E`).


## Struktur Data dan Algoritma yang Digunakan

* **Struktur Data:** *Priority Queue* (Min-Heap), *Vector/ArrayList*, *Struct/Class* untuk *Node* dan *Edge*.
* **Algoritma:** Dijkstra Algorithm (Modifikasi untuk graf berarah/Multistage Graph).

## 👥 Anggota Kelompok

| No. | Nama | NIM |
| :---: | :--- | :--- |
| 1 | Cornelius Fransinatra Wijaya | 21120124140141 |
| 2 | Ashar Firdaus | 21120124130062 |
| 3 | Andre Jonathan Tampubolon | 21120124130050 |

---

*Dibuat untuk memenuhi Tugas Besar Mata Kuliah Algoritma & Pemrograman, Departemen Teknik Komputer, Universitas Diponegoro.* 

---
