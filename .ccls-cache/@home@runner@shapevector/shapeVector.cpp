#ifndef SHAPEVECTOR_H_
#define SHAPEVECTOR_H_
template <typename T> class shapeVector {
  int size_v;
  T *elem;
  int space_v;

public:
  shapeVector() : size_v{0}, elem{nullptr}, space_v{0} {}       // default con
  shapeVector(int s) : size_v{0}, elem{new T[s]}, space_v{s} {} // alternate con
  shapeVector(const shapeVector &other) // copy constructor
      : size_v{other.size_v}, elem{new T[other.size_v]}, space_v{other.size.v} {
    for (int i = 0; i < size_v; i++) {
      elem[i] = other.elem[i];
    }
  }

  shapeVector &operator=(const shapeVector &other) { // copy assignment
    if (this != &other) {
      delete[] elem;
      size_v = other.size_v;
      elem = new T[size_v];
      space_v = size_v;
      for (int i = 0; i < size_v; ++i) {
        elem[i] = other.elem[i];
      }
    }
    return *this;
  }

  // move constructor
  shapeVector(shapeVector &&other) noexcept
      : size_v{other.size_v}, elem{other.elem}, space_v{other.space_v} {
    other.size_v = 0;
    other.elem = nullptr;
    other.space = 0;
  }

  // move assignment
  shapeVector &operator=(shapeVector &&other) noexcept {
    if (this != &other) {
      delete[] elem;
      size_v = other.size_v;
      elem = other.elem;
      space_v = other.space;
      other.size_v = 0;
      other.elem = nullptr;
      other.space = 0;
    }
    return *this;
  }

  // destructor
  ~shapeVector() { delete[] elem; }

  // access: return reference
  T &operator[](int n) { return elem[n]; }

  // access: return reference
  const T &operator[](int n) const { return elem[n]; }

  // current size
  int size() const { return size_v; }

  // current available space
  int capacity() const { return space_v; }

  // grow
  void resize(int newsize) {
    reserve(newsize);
    for (int i = size_v; i < newsize; ++i) {
      elem[i] = T();
    }
    size_v = newsize;
  }

  // add element
  void push_back(T val) {
    if (space_v == 0) {
      reserve(8);
    } else if (size_v == space_v) {
      reserve(space_v * 2);
    }
    elem[size_v] = val;
    ++size_v;
  }

  // get more space
  void reserve(int newalloc) {
    if (newalloc <= space_v) {
      return;
    }
    T *newelem = new T[newalloc];
    for (int i = 0; i < size_v; ++i) {
      newelem[i] = elem[i];
    }
    delete[] elem;
    elem = newelem;
    space_v = newalloc;
  }
};
class Shape {

private:
  int x1;
  int *px;

public:
  Shape(int s) : x1{s} {}
};
#endif