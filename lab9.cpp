#include <vector>
#include <iostream>

typedef std::vector<std::vector<float> > matrix;
typedef std::vector<float> vect;
typedef unsigned int uint;


matrix *getBlankField(uint, uint);
vect *getBlankVector(uint);

void itera(matrix&, matrix&, uint);
vect* Jacobi(const matrix&, vect&, float);
float norm1(const matrix&);
float magnitude(const vect&);
float sqrt(float);

int main() {
	matrix* A = getBlankField(4,4);
	vect* b = getBlankVector(4);

	A->at(0).at(0) = 13.40;
	A->at(0).at(1) = 5.81;
	A->at(0).at(2) = 0.70;
	A->at(0).at(3) = 0.82;

	A->at(1).at(0) = 0.41;
	A->at(1).at(1) = 12.50;
	A->at(1).at(2) = 6.50;
	A->at(1).at(3) = 0.77;
	
	A->at(2).at(0) = 0.36;
	A->at(2).at(1) = 0.48;
	A->at(2).at(2) = 11.60;
	A->at(2).at(3) = 7.18;

	A->at(3).at(0) = 0.31;
	A->at(3).at(1) = 0.43;
	A->at(3).at(2) = 0.54;
	A->at(3).at(3) = 10.70;

	b->at(0) = 17.7828;
	b->at(1) = 19.0599;
	b->at(2) = 19.9744;
	b->at(3) = 20.5261;

	vect* answer = Jacobi(*A, *b, 0.0001); // <- вернет ответ в виде вектора

	for (uint i = 0; i < answer->size(); i++) {
		std::cout << answer->at(i) << std::endl;
	}
}

matrix *getBlankField(uint rows, uint cols) {
	matrix *field = new matrix();
	for (uint i = 0; i < rows; i++) {
		field->push_back(std::vector<float>());
		for (uint j = 0; j < cols; j++) {
			(field->at(i)).push_back(false);
		}
	}
	return field;
}

vect *getBlankVector(uint len) {
	vect *v = new vect();
	for (uint i = 0; i < len; i++) {
		v->push_back(false);
	}
	return v;
}

void itera(matrix &B, const matrix &A, uint n) {
	for (uint i = 0; i < n; i++) {
		float alpha = 1.0 / (float)A[i][i];
		for (uint j = 0; j < n; j++) {
			B[i][j] = (i == j ? 0 : A[i][j] * alpha);
		}
	}
}

vect* Jacobi(const matrix &A, vect& b, float epsilon) { //matrix &B, 
	uint n = A[0].size();
	matrix* B = getBlankField(n, n);
	itera(*B, A, n);
	
	vect* c = getBlankVector(n);
	vect* x = getBlankVector(n);
	vect* x1 = getBlankVector(n);

	for (uint i = 0; i < n; i++) {
		c->at(i) = b[i] / A[i][i];
		x->at(i) = 0.0;
		x1->at(i) = c->at(i);
	}

	float norm = norm1(*B);

	if (norm >= 1) {
		vect* out = getBlankVector(n);
		for (uint i = 0; i < n; i++) {
			out->at(i) = norm;
		}

		return out;
	}

	while (norm > epsilon) {
		for (uint i = 0; i < n; i++) {
			float sum = 0;
			for (uint j = 0; j < n; j++) {
				sum += x1->at(j) * B->at(i)[j];
			}
			x->at(i) = c->at(i) + sum;
			
			norm = magnitude(*x1);

			for (uint j = 0; j < n; j++) {
				x1->at(j) = x->at(j) - x1->at(j);
			}
			norm = magnitude(*x1) / norm;

			for (uint j = 0; j < n; j++) {
				x1->at(j) = x->at(j);
			}
		}
	}
	return x;
}

float norm1(const matrix &m) {
	uint n = m.size();

	float max = 0;
	for (uint i = 0; i < n; i++) {
		float sum = 0;
		for (uint j = 0; j < n; j++) {
			sum += m[i][j];
		}
		if (sum > max) {
			max = sum;
		}
	}

	return max;
}

float magnitude(const vect &v) {
	float sum = 0;
	for (uint i = 0; i < v.size(); i++) {
		sum += v[i] * v[i];
	}
	
	return sqrt(sum);
}

float sqrt(float _val) {
	float low = 0;
	float high = _val;
	float mid = 0;
	while (high - low > 0.00001) {
		mid = low + (high - low) / 2;
		if (mid*mid > _val) {
			high = mid;
		} else {
			low = mid;
		}    
	}
	return mid;
}
