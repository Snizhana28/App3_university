#pragma once
namespace ASD {
	class ArrayException {
		int code;
		public: 
			ArrayException(int c) { code = c; }
			const char * Error() {
				if (code == 1) return "Error index";
				if (code == 2) return "Error allow memory";
				return "Unknown error";
			}
	};

	template <class T>
	class Array {
		T *ar;
		unsigned int count, size, grow;
	public:
		Array(unsigned s = 10, unsigned g = 5) {
			size = 0; count = 0;
			grow = g;
			ar = 0; 
			SetSize(s);
		}

		Array(Array & ar1) { ar = 0; Copy(ar1); }

		~Array() { 
			delete []ar; 
		}

		unsigned int GetCount() { return count; }
		unsigned int GetGrow() { return grow; }
		unsigned int GetSize() { return size; }
		T& operator[](int i) { if (i >= GetCount()) { throw ArrayException(1); } return ar[i]; }

		Array & operator = (Array & ar1) { return Copy(ar1);}
		Array & operator << (T e) { return Add(e); }
		Array & operator += (T e) { return Add(e); }
		Array & RemoveAll() { count = 0; return *this; }
		Array & FreeExtra() { SetSize(count); return *this; }

		Array & Copy(Array & ar1) {
			delete ar;
			size = 0; count = 0;
			grow = ar1.GetGrow();
			SetSize(ar1.GetCount());
			for (int i = 0; i < ar1.GetCount(); i++) {
				add(ar1[i]);
			}
			return *this;
		}

		Array & SetSize(unsigned int new_size) {
			if (new_size == size) return *this;
			T * new_ar = 0;
			if (new_size > 0) {
				new_ar = new T[new_size];
				if (!new_ar) throw 2;
				for (unsigned int i = 0; i < count && i < new_size; i++) {
					new_ar[i] = ar[i];
				}
			}
			if (ar) delete[]ar;
			ar = new_ar;
			size = new_size;
			return *this;
		}

		Array & Add(T e) {
			if (count >= size) {
				SetSize(size + grow);
			}
			ar[count++] = e;
			return *this;
		}

		Array & RemoveAt(unsigned int pos) {
			if (pos >= GetCount()) { throw ArrayException(1); }
			for (unsigned int i = pos + 1; i < count; i++) {
				ar[i - 1] = ar[i];
			}
			count--;
			return *this;
		}

		T & Find(T a) {
			for (unsigned int i = 0; i < count; i++) {
				if (ar[i] == a) {
					return ar[i];
				}
			}
			throw ArrayException(1);
		}

		unsigned int FindIndex(T a) {
			for (unsigned int i = 0; i < count; i++) {
				if (ar[i] == a) {
					return i;
				}
			}
			throw ArrayException(1);
		}

		void CalculateSumAndProduct(Array<int>& arr) {
			int sum = 0;
			int product = 1;

			for (unsigned int i = 0; i < arr.GetCount(); i += 2) {
				if (arr[i] > 0) {
					sum += arr[i];
					product *= arr[i];
				}
			}

			std::cout << "Sum : " << sum << " Product : " << product << std::endl;
		}
	};
}
