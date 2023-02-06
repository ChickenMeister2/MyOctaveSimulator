#include <stdio.h>
#include <stdlib.h>

#define CONDEXIT1 command != 'L'
#define CONDEXIT2 command != 'D'
#define CONDEXIT3 command != 'P'
#define CONDEXIT4 command != 'C'
#define CONDEXIT5 command != 'M'
#define CONDEXIT6 command != 'O'
#define CONDEXIT7 command != 'T'
#define CONDEXIT8 command != 'R'
#define CONDEXIT9 command != 'F'
#define CONDEXIT10 command != 'Q'
#define MOD 10007
#define NRCOLS 1
#define NRROWS 0

int main(void) {
char command = 'o';
int ***matrix_collection, rows, columns, matrix_count = -1, searched_index,
											**size_matrix, *sum_vector,
											**auxmatrix2, **auxmatrix, i, j;
while (scanf(" %c", &command)) {
	// in cazul in care comanda introdusa nu este printre cele suportate
	if (CONDEXIT1 && CONDEXIT2 && CONDEXIT3 && CONDEXIT4 && CONDEXIT5 &&
		CONDEXIT6 && CONDEXIT7 && CONDEXIT8 && CONDEXIT9 && CONDEXIT10)
		printf("Unrecognized command\n");
	// comanda de introducere a unei matrice in memorie
	else if (command == 'L') {
		scanf("%d%d", &rows, &columns);
		matrix_count++;
		if (matrix_count == 0) {
			sum_vector = malloc(1 * sizeof(int));
			if (sum_vector == NULL) {
				fprintf(stderr, "Out of memory");
				exit(EXIT_FAILURE);
			}
			matrix_collection = (int ***)malloc(sizeof(int **));
			if (matrix_collection == NULL) {
				fprintf(stderr, "Out of memory");
				exit(EXIT_FAILURE);
			}
		} else if (matrix_count > 0) {
			sum_vector =
				realloc(sum_vector, sizeof(int) * (matrix_count + 1));
			if (sum_vector == NULL) {
				fprintf(stderr, "Out of memory");
				exit(EXIT_FAILURE);
			}
			matrix_collection = (int ***)realloc(
				matrix_collection, sizeof(int ***) * (matrix_count + 1));
		}
		if (matrix_collection == NULL) {
			fprintf(stderr, "Out of memory");
			exit(EXIT_FAILURE);
		}
		matrix_collection[matrix_count] =
			(int **)calloc(rows, sizeof(int *));

		if (matrix_collection[matrix_count] == NULL) {
			fprintf(stderr, "Out of memory");
			for (i = 0; i <= matrix_count; i++) free(matrix_collection[i]);
			free(matrix_collection);
			exit(EXIT_FAILURE);
		}
		for (i = 0; i < rows; i++) {
			matrix_collection[matrix_count][i] =
				(int *)malloc(columns * sizeof(int));
			if (matrix_collection[matrix_count][i] == NULL) {
				fprintf(stderr, "Out of memory");
				for (i = 0; i <= matrix_count; i++) {
					for (j = 0; j < size_matrix[matrix_count][NRROWS]; j++)
						free(matrix_collection[i][j]);
					free(matrix_collection[i]);
				}
				free(matrix_collection);
				exit(EXIT_FAILURE);
			}
		}
		sum_vector[matrix_count] = 0;
		for (i = 0; i < rows; i++)
			for (j = 0; j < columns; j++) {
				scanf("%d", &matrix_collection[matrix_count][i][j]);
				sum_vector[matrix_count] +=
					matrix_collection[matrix_count][i][j];
			}
		sum_vector[matrix_count] %= MOD;
		if (sum_vector[matrix_count] < 0) sum_vector[matrix_count] += MOD;
		if (matrix_count == 0) {
			size_matrix = (int **)malloc(sizeof(int *));
			if (size_matrix == NULL) {
				fprintf(stderr, "Out of memory");
				free(size_matrix);
				exit(EXIT_FAILURE);
			}
			size_matrix[matrix_count] = (int *)malloc(2 * sizeof(int));
			if (size_matrix[matrix_count] == NULL) {
				fprintf(stderr, "Out of memory");
				free(size_matrix[matrix_count]);
				exit(EXIT_FAILURE);
			}
		}
		if (matrix_count > 0) {
			size_matrix =
				realloc(size_matrix, sizeof(int *) * (matrix_count + 1));
			if (size_matrix == NULL) {
				fprintf(stderr, "Out of memory");
				free(size_matrix);
				exit(EXIT_FAILURE);
			}
			size_matrix[matrix_count] = (int *)malloc(2 * sizeof(int));
			if (size_matrix[matrix_count] == NULL) {
				fprintf(stderr, "Out of memory");
				for (j = 0; j <= matrix_count; j++) free(size_matrix[j]);
				free(size_matrix);
				exit(EXIT_FAILURE);
			}
		}
		size_matrix[matrix_count][NRROWS] = rows;
		size_matrix[matrix_count][NRCOLS] = columns;
	}
	// comanda pentru afisarea dimensiunilor unei matrice
	else if (command == 'D') {
		scanf("%d", &searched_index);
		if (searched_index > matrix_count || searched_index < 0) {
			printf("No matrix with the given index\n");
			continue;
		}
		printf("%d %d\n", size_matrix[searched_index][NRROWS],
				size_matrix[searched_index][NRCOLS]);
		// comanda pentru afisarea unei matrice cu index mentionat
	} else if (command == 'P') {
		scanf("%d", &searched_index);
		if (searched_index > matrix_count || searched_index < 0) {
			printf("No matrix with the given index\n");
			continue;
		}
		for (i = 0; i < size_matrix[searched_index][NRROWS]; i++) {
			for (j = 0; j < size_matrix[searched_index][NRCOLS]; j++) {
				printf("%d ", matrix_collection[searched_index][i][j]);
			}
			printf("\n");
		}
	} else if (command == 'C') {
		scanf("%d", &searched_index);
		int res_row, res_col;
		scanf("%d", &res_row);
		int *rows = (int *)malloc(res_row * sizeof(int));
		if (rows == NULL) {
			fprintf(stderr, "Out of memory");
			free(rows);
			exit(EXIT_FAILURE);
		}
		for (i = 0; i < res_row; i++) scanf("%d", &rows[i]);

		scanf("%d", &res_col);
		int *cols = (int *)malloc(res_col * sizeof(int));

		if (cols == NULL) {
			fprintf(stderr, "Out of memory");
			free(cols);
			exit(EXIT_FAILURE);
		}

		for (i = 0; i < res_col; i++) {
			scanf("%d", &cols[i]);
		}
		if (searched_index > matrix_count || searched_index < 0) {
			free(cols);
			free(rows);
			printf("No matrix with the given index\n");
			continue;
		} else {
			auxmatrix = (int **)malloc(res_row * sizeof(int *));
			if (auxmatrix == NULL) {
				fprintf(stderr, "Out of memory");
				free(auxmatrix);
				exit(EXIT_FAILURE);
			}
			for (i = 0; i < res_row; i++) {
				auxmatrix[i] = (int *)malloc(res_col * sizeof(int));
				if (auxmatrix[i] == NULL) {
					for (j = 0; j < i; j++) free(auxmatrix[i]);
					free(auxmatrix);
					exit(EXIT_FAILURE);
				}
			}
			sum_vector[searched_index] = 0;
			for (i = 0; i < res_row; i++)
				for (j = 0; j < res_col; j++)
					auxmatrix[i][j] =
						matrix_collection[searched_index][rows[i]][cols[j]];
			for (i = 0; i < size_matrix[searched_index][0]; i++)
				free(matrix_collection[searched_index][i]);
			for (i = 0; i < res_row; i++)
				matrix_collection[searched_index][i] =
					malloc(res_col * sizeof(int));
			size_matrix[searched_index][NRROWS] = res_row;
			size_matrix[searched_index][NRCOLS] = res_col;
			for (i = 0; i < res_row; i++)
				for (j = 0; j < res_col; j++) {
					matrix_collection[searched_index][i][j] =
						auxmatrix[i][j];
					sum_vector[searched_index] +=
						matrix_collection[searched_index][i][j];
					sum_vector[searched_index] %= MOD;
					if (sum_vector[searched_index] < 0)
						sum_vector[searched_index] += MOD;
				}
			//eliberez spatiul alocat pt vectorii si matricea auxiliara
			free(cols);
			free(rows);
			for (i = 0; i < res_row; i++)
				free(auxmatrix[i]);
			free(auxmatrix);
		}
	} else if (command == 'M') {
		int firstmatrixindex, secondmatrixindex;
		scanf("%d%d", &firstmatrixindex, &secondmatrixindex);
		if (firstmatrixindex > matrix_count ||
			secondmatrixindex > matrix_count) {
			printf("No matrix with the given index\n");
			continue;
		}
		if (size_matrix[firstmatrixindex][NRCOLS] !=
			size_matrix[secondmatrixindex][NRROWS]) {
			printf("Cannot perform matrix multiplication\n");
			continue;
		}
		matrix_count++;
		size_matrix =
			realloc(size_matrix, sizeof(int *) * (matrix_count + 1));
		if (size_matrix == NULL) {
			fprintf(stderr, "Out of memory");
			free(size_matrix);
			exit(EXIT_FAILURE);
		}
		size_matrix[matrix_count] = (int *)malloc(2 * sizeof(int));
		if (size_matrix[matrix_count] == NULL) {
			fprintf(stderr, "Out of memory");
			for (j = 0; j <= matrix_count; j++) free(size_matrix[j]);
			free(size_matrix);
			exit(EXIT_FAILURE);
		}
		size_matrix[matrix_count][NRROWS] =
			size_matrix[firstmatrixindex][NRROWS];
		size_matrix[matrix_count][NRCOLS] =
			size_matrix[secondmatrixindex][NRCOLS];
		matrix_collection = (int ***)realloc(
			matrix_collection, sizeof(int ***) * (matrix_count + 1));
		if (matrix_collection == NULL) {
			fprintf(stderr, "Out of memory");
			exit(EXIT_FAILURE);
		}
		matrix_collection[matrix_count] = (int **)malloc(
			size_matrix[firstmatrixindex][NRROWS] * sizeof(int *));
		if (matrix_collection[matrix_count] == NULL) {
			fprintf(stderr, "Out of memory");
			for (i = 0; i <= matrix_count; i++) free(matrix_collection[i]);
			free(matrix_collection);
			exit(EXIT_FAILURE);
		}
		for (i = 0; i < size_matrix[firstmatrixindex][NRROWS]; i++) {
			matrix_collection[matrix_count][i] = (int *)malloc(
				size_matrix[secondmatrixindex][NRCOLS] * sizeof(int));
			if (matrix_collection[matrix_count][i] == NULL) {
				fprintf(stderr, "Out of memory");
				for (i = 0; i <= matrix_count; i++) {
					for (j = 0; j < size_matrix[matrix_count][NRROWS]; j++)
						free(matrix_collection[i][j]);
					free(matrix_collection[i]);
				}
				free(matrix_collection);
				exit(EXIT_FAILURE);
			}
		}
		sum_vector = realloc(sum_vector, sizeof(int) * (matrix_count + 1));
		if (sum_vector == NULL) {
			fprintf(stderr, "Out of memory");
			exit(EXIT_FAILURE);
		}// resetez cu 0 suma din ultima matrice
		sum_vector[matrix_count] = 0;
		// efectuez inmultirea
		for (i = 0; i < size_matrix[firstmatrixindex][NRROWS]; i++)
			for (j = 0; j < size_matrix[secondmatrixindex][NRCOLS]; j++) {
				matrix_collection[matrix_count][i][j] = 0;
				for (int k = 0; k < size_matrix[secondmatrixindex][NRROWS];
						k++) {
					matrix_collection[matrix_count][i][j] +=
						matrix_collection[firstmatrixindex][i][k] *
						matrix_collection[secondmatrixindex][k][j];
					matrix_collection[matrix_count][i][j] %= MOD;
					if (matrix_collection[matrix_count][i][j] < 0)
						matrix_collection[matrix_count][i][j] += MOD;
				}
			}// recalculez suma
		for (i = 0; i < size_matrix[matrix_count][NRROWS]; i++)
			for (j = 0; j < size_matrix[matrix_count][NRCOLS]; j++) {
				sum_vector[matrix_count] +=
					matrix_collection[matrix_count][i][j];
				sum_vector[matrix_count] %= MOD;
				if (sum_vector[matrix_count] < 0)
					sum_vector[matrix_count] += MOD;
			}

	} else if (command == 'O') {
		// ordonez prin interschimbare matricele crescator dupa suma
		for (i = 0; i < matrix_count; i++)
			for (j = i + 1; j <= matrix_count; j++)
				if (sum_vector[i] > sum_vector[j]) {
					int **aux = matrix_collection[i];
					matrix_collection[i] = matrix_collection[j];
					matrix_collection[j] = aux;

					int aux2 = size_matrix[i][NRROWS];
					size_matrix[i][NRROWS] = size_matrix[j][NRROWS];
					size_matrix[j][NRROWS] = aux2;

					aux2 = size_matrix[i][NRCOLS];
					size_matrix[i][NRCOLS] = size_matrix[j][NRCOLS];
					size_matrix[j][NRCOLS] = aux2;

					aux2 = sum_vector[i];
					sum_vector[i] = sum_vector[j];
					sum_vector[j] = aux2;
				}
	} else if (command == 'T') {
		scanf("%d", &searched_index);
		if (searched_index > matrix_count) {
			printf("No matrix with the given index\n");
			continue;
		}
		auxmatrix = (int **)calloc(size_matrix[searched_index][NRCOLS],
									sizeof(int *));
		if (auxmatrix == NULL) {
			fprintf(stderr, "Out of memory");
			exit(EXIT_FAILURE);
		}
		for (i = 0; i < size_matrix[searched_index][NRCOLS]; i++) {
			auxmatrix[i] =
				malloc(size_matrix[searched_index][NRROWS] * sizeof(int));
			if (auxmatrix[i] == NULL) {
				for (j = 0; j < i; j++) free(auxmatrix[i]);
				free(auxmatrix);
				fprintf(stderr, "Out of memory");
				exit(EXIT_FAILURE);
			}
		}

		for (i = 0; i < size_matrix[searched_index][NRROWS]; i++)
			for (j = 0; j < size_matrix[searched_index][NRCOLS]; j++)
				auxmatrix[j][i] = matrix_collection[searched_index][i][j];

		for (i = 0; i < size_matrix[searched_index][NRROWS]; i++)
			free(matrix_collection[searched_index][i]);
		free(matrix_collection[searched_index]);

		int aux = size_matrix[searched_index][NRCOLS];
		size_matrix[searched_index][NRCOLS] =
			size_matrix[searched_index][NRROWS];
		size_matrix[searched_index][NRROWS] = aux;

		matrix_collection[searched_index] = (int **)malloc(
			size_matrix[searched_index][NRROWS] * sizeof(int *));
		for (i = 0; i < size_matrix[searched_index][NRROWS]; i++)
			matrix_collection[searched_index][i] = (int *)malloc(
				size_matrix[searched_index][NRCOLS] * sizeof(int));

		for (i = 0; i < size_matrix[searched_index][NRROWS]; i++)
			for (j = 0; j < size_matrix[searched_index][NRCOLS]; j++)
				matrix_collection[searched_index][i][j] = auxmatrix[i][j];

		for (i = 0; i < size_matrix[searched_index][NRROWS]; i++)
			free(auxmatrix[i]);
		free(auxmatrix);


	} else if (command == 'R') {
		int power;
		scanf("%d", &searched_index);
		scanf("%d", &power);
		if (searched_index > matrix_count || searched_index < 0) {
			printf("No matrix with the given index\n");
			continue;
		}
		if (power < 0) {
			printf("Power should be positive\n");
			continue;
		}
		if (size_matrix[searched_index][NRROWS] !=
			size_matrix[searched_index][NRCOLS]) {
			printf("Cannot perform matrix multiplication\n");

		} else {
			int **identity_matrix = (int **)malloc(
				size_matrix[searched_index][NRROWS] * sizeof(int *));
			if (identity_matrix == NULL) {
				fprintf(stderr, "Out of memory");
				free(identity_matrix);
				exit(EXIT_FAILURE);
			}
			for (i = 0; i < size_matrix[searched_index][NRROWS]; i++) {
				identity_matrix[i] = (int *)malloc(
					size_matrix[searched_index][NRCOLS] * sizeof(int));
				if (identity_matrix[i] == NULL) {
					for (j = 0; j < i; j++) free(identity_matrix[i]);
					free(identity_matrix);
					exit(EXIT_FAILURE);
				}
			} // creez matricea identitate
			for (i = 0; i < size_matrix[searched_index][NRROWS]; i++)
				for (j = 0; j < size_matrix[searched_index][NRCOLS]; j++) {
					if (i == j)
						identity_matrix[i][j] = 1;
					else
						identity_matrix[i][j] = 0;
				}

			auxmatrix2 = (int **)malloc(
				size_matrix[searched_index][NRROWS] * sizeof(int *));
			if (auxmatrix2 == NULL) {
				fprintf(stderr, "Out of memory");
				free(auxmatrix2);
				exit(EXIT_FAILURE);
			}
			for (i = 0; i < size_matrix[searched_index][NRROWS]; i++) {
				auxmatrix2[i] = (int *)malloc(
					size_matrix[searched_index][NRCOLS] * sizeof(int));
				if (auxmatrix2[i] == NULL) {
					for (j = 0; j < i; j++) free(auxmatrix2[i]);
					free(auxmatrix2);
					exit(EXIT_FAILURE);
				}
			}
			int **rezultat = (int **)malloc(
				size_matrix[searched_index][NRROWS] * sizeof(int *));
			if (rezultat == NULL) {
				fprintf(stderr, "Out of memory");
				free(rezultat);
				exit(EXIT_FAILURE);
			}
			for (i = 0; i < size_matrix[searched_index][NRROWS]; i++) {
				rezultat[i] = (int *)malloc(
					size_matrix[searched_index][NRCOLS] * sizeof(int));
				if (rezultat[i] == NULL) {
					for (j = 0; j < i; j++) free(rezultat[i]);
					free(rezultat);
					exit(EXIT_FAILURE);
				}
			}
			while (power) {
				if (power % 2 == 1) {
					// element neutru = element neutru * matrice
					// in cazul in care puterea e impara
					for (i = 0; i < size_matrix[searched_index][NRROWS];
							i++)
						for (j = 0; j < size_matrix[searched_index][NRROWS];
								j++) {
							rezultat[i][j] = 0;
							for (int k = 0;
									k < size_matrix[searched_index][NRROWS];
									k++) {
								rezultat[i][j] +=
									matrix_collection[searched_index][i]
														[k] *
									identity_matrix[k][j];
								rezultat[i][j] %= MOD;
								if (rezultat[i][j] < 0)
									rezultat[i][j] += MOD;
							}
						}
					// copiez rezultatul in "matricea identitate"
					for (i = 0; i < size_matrix[searched_index][NRROWS];
							i++)
						for (j = 0; j < size_matrix[searched_index][NRROWS];
								j++)
							identity_matrix[i][j] = rezultat[i][j];
				}

				for (i = 0; i < size_matrix[searched_index][NRROWS]; i++)
					for (j = 0; j < size_matrix[searched_index][NRROWS];
							j++)
						for (i = 0; i < size_matrix[searched_index][NRROWS];
								i++)
							for (j = 0;
									j < size_matrix[searched_index][NRROWS];
									j++) {
								auxmatrix2[i][j] = 0;
								for (int k = 0;
										k <
										size_matrix[searched_index][NRROWS];
										k++) {
									auxmatrix2[i][j] +=
										matrix_collection[searched_index][i]
															[k] *
										matrix_collection[searched_index][k]
															[j];
									auxmatrix2[i][j] %= MOD;
									if (auxmatrix2[i][j] < 0)
										auxmatrix2[i][j] += MOD;
								}
							}

				for (i = 0; i < size_matrix[searched_index][NRROWS]; i++)
					for (j = 0; j < size_matrix[searched_index][NRROWS];
							j++) {
						matrix_collection[searched_index][i][j] =
							auxmatrix2[i][j];
					}
				power = power / 2;
			}
			// resetez suma
			sum_vector[searched_index] = 0;
			// introduc in matricea initiala rezultatul
			for (i = 0; i < size_matrix[searched_index][NRROWS]; i++)
				for (j = 0; j < size_matrix[searched_index][NRROWS]; j++) {
					matrix_collection[searched_index][i][j] =
						rezultat[i][j];
					sum_vector[searched_index] +=
						matrix_collection[searched_index][i][j];
					sum_vector[searched_index] %= MOD;
					if (sum_vector[searched_index] < 0)
						sum_vector[searched_index] += MOD;
				}
			//eliberez spatiul folosit de matricele auxiliare
			for (i = 0; i < size_matrix[searched_index][NRROWS]; i++) {
				free(rezultat[i]);
				free(identity_matrix[i]);
				free(auxmatrix2[i]);
			}
			free(rezultat);
			free(identity_matrix);
			free(auxmatrix2);
		}
	} else if (command == 'F') {
		scanf("%d", &searched_index);
		if (searched_index > matrix_count || searched_index < 0) {
			printf("No matrix with the given index\n");
			continue;
		}// eliberez memoria folosita de matricea eliminata
		for (i = 0; i < size_matrix[searched_index][NRROWS]; i++)
			free(matrix_collection[searched_index][i]);
		free(matrix_collection[searched_index]);
		free(size_matrix[searched_index]);
		// mut toate matricele cu un index in jos
		for (i = searched_index; i < matrix_count; i++) {
			sum_vector[i] = sum_vector[i + 1];
			matrix_collection[i] = matrix_collection[i + 1];
			size_matrix[i] = size_matrix[i + 1];
		}// scad numarul de matrice
		matrix_count--;
		matrix_collection = (int ***)realloc(
			matrix_collection, (matrix_count + 1) * sizeof(int **));
		size_matrix = (int **)realloc(size_matrix,
										(matrix_count + 1) * sizeof(int *));
		sum_vector = realloc(sum_vector, (matrix_count + 1) * sizeof(int));
	} else if (command == 'Q') {
		// daca nu s-a citit nicio matrice doar inchid programul
		if (matrix_count == -1)
			break;
		// daca s-au citit matrice atunci voi dezaloca memoria
		else if (matrix_count >= 0) {
			for (i = 0; i <= matrix_count; i++) {
				for (j = 0; j < size_matrix[i][NRROWS]; j++)
					free(matrix_collection[i][j]);
				free(matrix_collection[i]);
			}

			free(matrix_collection);
			for (i = 0; i <= matrix_count; i++) free(size_matrix[i]);
			free(size_matrix);
			free(sum_vector);
			break;
		}
	}
}
}