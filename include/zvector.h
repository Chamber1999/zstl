#include <iostream>
namespace zstl {
template <typename T> class zvector {
public:
  zvector();
  ~zvector();
  void push_back(const T &t);
  void pop_back();
  T &operator[](int index);
  int size() const;
  int capacity() const;
  bool empty() const;
  void clear();
  void reserve(int size);
  void resize(int size);
  void insert(int index, const T &t);
  void erase(int index);
  void erase(int start, int end);
  void swap(zvector<T> &other);
  void sort();
  void reverse();
  void unique();
  void merge(zvector<T> &other);
  void print();
  void print_reverse();

private:
  T *m_data;
  int m_size;
  int m_capacity;
};
} // namespace zstl
using namespace zstl;
template <typename T> zvector<T>::zvector() {
  m_data = nullptr;
  m_size = 0;
  m_capacity = 0;
}
template <typename T> zvector<T>::~zvector() {
  if (m_data != nullptr) {
    delete[] m_data;
    m_data = nullptr;
  }
}
template <typename T> void zvector<T>::push_back(const T &t) {
  if (m_data == nullptr) {
    m_data = new T[1];
    m_data[0] = t;
    m_size = 1;
    m_capacity = 1;
  } else {
    if (m_size == m_capacity) {
      T *temp = new T[m_capacity * 2];
      for (int i = 0; i < m_size; i++) {
        temp[i] = m_data[i];
      }
      delete[] m_data;
      m_data = temp;
      m_data[m_size] = t;
      m_size++;
      m_capacity *= 2;
    } else {
      m_data[m_size] = t;
      m_size++;
    }
  }
}
template <typename T> void zvector<T>::pop_back() {
  if (m_data != nullptr) {
    m_size--;
  }
}
template <typename T> T &zvector<T>::operator[](int index) {
  return m_data[index];
}
template <typename T> int zvector<T>::size() const { return m_size; }
template <typename T> int zvector<T>::capacity() const { return m_capacity; }
template <typename T> bool zvector<T>::empty() const {
  if (m_size == 0) {
    return true;
  } else {
    return false;
  }
}
template <typename T> void zvector<T>::clear() {
  if (m_data != nullptr) {
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
    m_capacity = 0;
  }
}
template <typename T> void zvector<T>::reserve(int size) {
  if (m_data == nullptr) {
    m_data = new T[size];
    m_capacity = size;
  } else {
    if (size > m_capacity) {
      T *temp = new T[size];
      for (int i = 0; i < m_size; i++) {
        temp[i] = m_data[i];
      }
      delete[] m_data;
      m_data = temp;
      m_capacity = size;
    }
  }
}
template <typename T> void zvector<T>::resize(int size) {
  if (m_data == nullptr) {
    m_data = new T[size];
    m_capacity = size;
    m_size = size;
  } else {
    if (size > m_capacity) {
      T *temp = new T[size];
      for (int i = 0; i < m_size; i++) {
        temp[i] = m_data[i];
      }
      delete[] m_data;
      m_data = temp;
      m_capacity = size;
      m_size = size;
    } else {
      m_size = size;
    }
  }
}
template <typename T> void zvector<T>::insert(int index, const T &t) {
  if (m_data == nullptr) {
    m_data = new T[1];
    m_data[0] = t;
    m_size = 1;
    m_capacity = 1;
  } else {
    if (m_size == m_capacity) {
      T *temp = new T[m_capacity * 2];
      for (int i = 0; i < m_size; i++) {
        temp[i] = m_data[i];
      }
      delete[] m_data;
      m_data = temp;
      m_size++;
      m_capacity *= 2;
    } else {
      for (int i = m_size; i > index; i--) {
        m_data[i] = m_data[i - 1];
      }
      m_data[index] = t;
      m_size++;
    }
  }
}
template <typename T> void zvector<T>::erase(int index) {
  if (m_data != nullptr) {
    for (int i = index; i < m_size - 1; i++) {
      m_data[i] = m_data[i + 1];
    }
    m_size--;
  }
}
template <typename T> void zvector<T>::erase(int start, int end) {
  if (m_data != nullptr) {
    int count = end - start + 1;
    for (int i = start; i < m_size - count; i++) {
      m_data[i] = m_data[i + count];
    }
    m_size -= count;
  }
}
template <typename T> void zvector<T>::swap(zvector<T> &other) {
  T *temp = m_data;
  m_data = other.m_data;
  other.m_data = temp;
  int temp_size = m_size;
  m_size = other.m_size;
  other.m_size = temp_size;
  int temp_capacity = m_capacity;
  m_capacity = other.m_capacity;
  other.m_capacity = temp_capacity;
}
template <typename T> void zvector<T>::sort() {
  if (m_data != nullptr) {
    for (int i = 0; i < m_size - 1; i++) {
      for (int j = 0; j < m_size - i - 1; j++) {
        if (m_data[j] > m_data[j + 1]) {
          T temp = m_data[j];
          m_data[j] = m_data[j + 1];
          m_data[j + 1] = temp;
        }
      }
    }
  }
}
template <typename T> void zvector<T>::print() {
  if (m_data != nullptr) {
    for (int i = 0; i < m_size; i++) {
      std::cout << m_data[i] << " ";
    }
    std::cout << std::endl;
  }
}
template <typename T> void zvector<T>::reverse() {
    if (m_data != nullptr) {
        for (int i = 0; i < m_size / 2; i++) {
        T temp = m_data[i];
        m_data[i] = m_data[m_size - i - 1];
        m_data[m_size - i - 1] = temp;
        }
    }
}
template <typename T> void zvector<T>::unique() {
    if (m_data != nullptr) {
        for (int i = 0; i < m_size - 1; i++) {
            if (m_data[i] == m_data[i + 1]) {
                erase(i);
                i--;
            }
        }
    }
}
template<typename T> void zvector<T>::merge(zvector<T> &other) {
    if (m_data != nullptr && other.m_data != nullptr) {
        int size = m_size + other.m_size;
        T *temp = new T[size];
        int i = 0, j = 0, k = 0;
        while (i < m_size && j < other.m_size) {
            if (m_data[i] < other.m_data[j]) {
                temp[k++] = m_data[i++];
            } else {
                temp[k++] = other.m_data[j++];
            }
        }
        while (i < m_size) {
            temp[k++] = m_data[i++];
        }
        while (j < other.m_size) {
            temp[k++] = other.m_data[j++];
        }
        delete[] m_data;
        m_data = temp;
        m_size = size;
        m_capacity = size;
    }
}
template<typename T> void zvector<T>::print_reverse(){
    if (m_data != nullptr) {
        for (int i = m_size - 1; i >= 0; i--) {
            std::cout << m_data[i] << " ";
        }
        std::cout << std::endl;
    }
}
