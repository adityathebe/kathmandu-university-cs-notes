class Matrix {

	constructor(rows, cols) {
		this.rows = rows;
		this.cols = cols;
		this.data = [];

		for (let i = 0; i < this.rows; i++) {
			this.data.push([]);
			for (let j = 0; j < this.cols; j++) {
				this.data[i].push(0);
			}
		}
	}

	randomize() {
		this.map(x => (Math.random() * 2) - 1 );	
	}

	multiply(n) {
		this.map(x => x * n);
	}

	add (n) {
		this.map(x => x + n);
	}

	setData(row, col, data) {
		this.data[row][col] = data;
	}

	// Returns a 1D array of a given matrix
	toArray () {
		let temp = [];

		for (var i = 0; i < this.rows; i++) {
			for (var j = 0; j < this.cols; j++) {
				temp.push( this.data[i][j] );
			}
		}

		return temp;
	}

	static fromArray (arr) {
		let newMat = new Matrix(arr.length, 1);
		for (let i = 0; i < arr.length; i++) {
			newMat.data[i][0] = arr[i];
		}
		return newMat;
	}

	static multiply (matA, matB) {

		if ( matA.cols !== matB.rows ) {
			console.log('Invalid matrix multiplication. <Invalid dimension>');
			return undefined;
		} else {

			let result = new Matrix(matA.rows, matB.cols);
			for ( let i = 0; i < matA.rows; i++) {
				for ( let j = 0; j < matA.cols; j++ ) {
					for (var k = 0; k < matB.cols ; k++) {
						let value = matA.data[i][j] * matB.data[j][k]
						result.data[i][k] += value;
					}
				}
			}

			return result;
		}
	}

	static add (matA, matB) {
		if ( matA.rows === matB.rows && matA.cols === matB.cols ) {
			let result = new Matrix(matA.rows, matA.cols);

			for (var i = 0; i < matA.rows; i++) {
				for (var j = 0; j < matA.cols; j++) {
					result.data[i][j] = matA.data[i][j] + matB.data[i][j];
				}
			}

			return result;

		} else {
			console.log('Invalid matrix addition. <Unmatching dimension>');
			return undefined;
		}
	}

	static subtract (matA, matB) {
		if ( matA.rows === matB.rows && matA.cols === matB.cols ) {
			let result = new Matrix(matA.rows, matA.cols);

			for (var i = 0; i < matA.rows; i++) {
				for (var j = 0; j < matA.cols; j++) {
					result.data[i][j] = matA.data[i][j] - matB.data[i][j];
				}
			}

			return result;

		} else {
			console.log('Invalid matrix subtraction. <Unmatching dimension>');
			return undefined;
		}
	}

	static tranpose(matA) {
		let temp = new Matrix(matA.cols, matA.rows);

		for (var i = 0; i < matA.rows; i++) {
			for (var j = 0; j < matA.cols; j++) {
				temp.data[j][i] = matA.data[i][j];
			}
		}
		
		return temp;
	}

	clone () {
		return this;
	}

	static clone (mat) {
		return mat;
	}

	map (func) {
		for (var i = 0; i < this.rows; i++) {
			for (var j = 0; j < this.cols; j++) {
				this.data[i][j] = func(this.data[i][j]);
			}
		}
	}
}