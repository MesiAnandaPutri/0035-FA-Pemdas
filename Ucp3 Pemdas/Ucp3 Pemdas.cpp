#include <iostream>
using namespace std;
class MasukUniversitas {
	private: 
	int uangPendaftaran;  // Enkapsulasi
	int uangSemesterPertama;
	int uangBangunan;
	int totalBiaya; // Membungkus variable dengan access modifier private
	
public:
	MasukUniversitas() {  // Construction
		uangPendaftaran = 0;
		uangSemesterPertama = 0;
		uangBangunan = 0;
		totalBiaya = 0;

		// isi nilai default variable yang dibutuhkan di bawah ini
	}
	virtual void namaJalurMasuk() { return; }   // Membuat pure function secara virtual agar bisa di overriding
	virtual void hitungTotalBiaya() { return; }
	virtual void tampilkanTotalBiaya() { return; }
	virtual void input() { return; }
	// isi disini dengan fungsi virtual yang dibutuhkan

	void setUangPendaftaran(int nilai) { // Mengeset variable yang telah dienkapsulasi dengan konsep abstraksi
		this->uangPendaftaran = nilai;
	}

	void setUangSemesterPertama(int nilai) {
		this->uangSemesterPertama = nilai;
	}

	void setUangBangunan(int nilai) {
		this->uangBangunan = nilai;
	}

	float getUangPendaftaran() { // Mengakses variable bil1 yang telah dienkapsulasi
		return uangPendaftaran;
	}

	float getUangSemesterPertama() {
		return uangSemesterPertama;
	}

	float getUangBangunan() {
		return uangBangunan;
	}
	// isi setter dan getter variable yang dibutuhkan di bawah ini
};
class SNBT : public MasukUniversitas { // Inheritance dari Masuk Universitas
private:
	int nilai;
public:
	SNBT() {    // Construction
		cout << "SNBT" << endl;
		cout << "------------" << endl;
	}
	void input() {   // Polymorphy function input
		cout << " Masukan Jumlah Nilai Pendaftaran = ";
		cin >> nilai;
		setUangPendaftaran(nilai);

		cout << " Masukan Jumlah Uang Semester =";
		cin >> nilai;
		setUangSemesterPertama(nilai);

		cout << " Masukan Jumlah Uang Bangunan = ";
		cin >> nilai;
		setUangBangunan(nilai);
		
	}

	int MasukUniversitas() {   // Polymorphy function Masuk University
		return getUangPendaftaran() + getUangSemesterPertama() + getUangBangunan();
	}

	void display() {    // Polymorphy function display
		cout << "=======================" << endl;
		cout << " Total Biaya " << this->MasukUniversitas() << endl;
		cout << "=======================" << endl;
	}
	// isi disini untuk melengkapi class SNBT
};
class SNBP : public MasukUniversitas { // Inheritance dari Masuk Universitas
private:
	int nilai;

public:
	SNBP() {   // Construction
		cout << "SNBP" << endl;
		cout << "-----------" << endl;
	}
	void input() {
		cout << " Masukan Jumlah Uang Pendaftaran = ";   // Polymorphy function input
		cin >> nilai;
		setUangPendaftaran(nilai);

		cout << " Masukan Jumlah Uang Semester Pertama = ";
		cin >> nilai;
		setUangSemesterPertama(nilai);
	}

	int MasukUniversitas() {   // Polymorphy function Masuk Universitas
		return getUangPendaftaran() + getUangSemesterPertama();
	}

	void display() {    // Polymorphy function display
		cout << "================" << endl;
		cout << "Total Biaya" << this->MasukUniversitas() << endl;
		cout << "================" << endl;
	}
	// isi disini untuk melengkapi class SNBP
};
int main() {
	int pilihan;
	SNBT a;
	SNBP b;
	while (true)
	{
		try {
			cout << "\n Pilih Jalur Masuk \n";
			cout << "1. SNBT\n";
			cout << "2. SNBP\n";
			cout << "Masukan Pilihan =";
			cin >> pilihan;

			switch (pilihan)
			{
			case 1:
				a;
				break;
			case 2:
				b;
				break;
			default:
				cout << "Pilihan Tidak Tersedia !";

			} 

			do {
				SNBT hitung1;
				hitung1.input();
				hitung1.display(); // membuat object dari SNBT

				SNBP hitung2;   // membuat object dari SNBP
				hitung2.input();
				hitung2.display();

				cout << "Apakah mau mengulangi program?(y/n) = ";
				cin >> pilihan;
				system("cls");
			} while ((pilihan == 'Y') || (pilihan == 'y'));
		}
		catch (exception& e){}
		return 0;
		// isi disini untuk fungsi main
	}
}
