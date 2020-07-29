class Matrix{
public:
    Matrix(int size);
    ~Matrix();
    void setMatrix(const double* values);
    void printMatrix() const;
    int getSize() const{ return size; }
    double &element(int i, int j){ return elements[i*size + j]; }
    double element(int i, int j) const{ return elements[i*size + j]; }
private:
    int size;
    double* elements;
};
