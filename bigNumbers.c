#include <stdio.h>
#define MAX 1024 // MAX < 65536

typedef struct bigNumber {
	unsigned tope;
	short signo;
	short numero[MAX];
} tBigNumber;

short numeroValido (char text[]) {
	short valido = 1;
	unsigned posicion = 0;
	if ('-' == text[posicion]) ++posicion;
	while (1 == valido && '\0' != text[posicion]) {
		if (48 > text[posicion] || 57 < text[posicion]) valido = 0;
		++posicion;
	}
	return valido;
}

void charToBigNumber (char text[], tigNumber *bigNumber) {
	unsigned posicion = 0;
	if ('-' == text[posicion]) {
		bigNumber->signo = 1;
		++posicion;
	} else {
		bigNumber->signo = 0;
	}
	while ('\0' != text[posicion]) {
		bigNumber->numero[posicion - bigNumber->signo] = text[posicion] - 48;
		++posicion;
	}
	bigNumber->tope = posicion - bigNumber->signo;
}

short esMayor (tBigNumber numeroA, tBigNumber numeroB) {
	short masGrande = 0;
	unsigned i = 0;
	if (numeroA.tope == numeroB.tope) {
		while (numeroA.numero[i] == numeroB.numero[i] && i < numeroA.tope)
			++i;
		if (numeroA.numero[i] > numeroB.numero[i])
			masGrande = 1;
	} else if (numeroA.tope > numeroB.tope) {
		masGrande = 1;
	}
	return masGrande;
}

/*
	funcion: suma y resta absoluta de dos bigNumber
	variable "tipo":
		1 para realizar suma
		-1 para realizar resta
*/
void calculo (tBigNumber numeroA, tBigNumber numeroB, tBigNumber *resultado, short tipo) {
	short carry = 0, posicionB;
	unsigned i;
	resultado->tope = numeroA.tope;
	for (i = numeroA.tope; i > 0; --i) {
		posicionB = numeroB.tope + (i - numeroA.tope - 1);
		resultado->numero[i-1] = numeroA.numero[i-1] + carry;
		if (posicionB >= 0)
			resultado->numero[i-1] = resultado->numero[i-1] + tipo * numeroB.numero[posicionB];
		carry = 0;
		if (10 <= resultado->numero[i-1] || 0 > resultado->numero[i-1]) {
			carry = tipo;
			resultado->numero[i-1] -= tipo * 10;
		}
	}
	if (tipo == carry) {
		if (1 == tipo) {
			//carry suma
			++resultado->tope;
			for (i = resultado->tope; i > 0; --i) {
				resultado->numero[i] = resultado->numero[i-1];
			}
			resultado->numero[0] = 1;
		} else {
			//carry resta
			resultado->numero[resultado->tope-1] = 10 - resultado->numero[resultado->tope-1];
			for (i = resultado->tope - 1; i > 0; --i)
				resultado->numero[i-1] = 9 - resultado->numero[i-1];
		}
	}
	//quita ceros del principio del vector
	while (resultado->tope > 1 && resultado->numero[0] == 0) {
		i = 0;
		while (i < resultado->tope - 1) {
			resultado->numero[i] = resultado->numero[i+1];
			++i;
		}
		--resultado->tope;
	}
}

void resta (tBigNumber primernumero, tBigNumber segundonumero, tBigNumber *resultado) {
	If primernumero.signo!=segundonumero.signo {
		´*resultado.signo=primernumero.signo;
		*resultado.numero=calculo(primernumero,segundonumero,1);
		If primernumero.tope>segundonumero.tope	
			*resultado.tope=primernumero.tope+1;
		else {
			If segundonumero.tope>primernumero.tope	
				*resultado.tope=segundonumero.tope+1;
			else
				*resultado.tope=primernumero.tope+1;
		}
		}
	else { 
		If primernumero>segundonumero {
			*resultado.signo=primernumero.signo;
			*resultado.numero=calculo(primernumero,segundonumero,-1);
			*resultado.tope=primernumero.tope
			}
		else {
			*resultado.signo=(segundonumero.signo*(-1));
			*resultado.numero=calculo(segundonumero,primernumero,-1);
			*resultado.tope=segundonumero.tope
			}
	}
}

void suma (tBigNumber primernumero, tBigNumber segundonumero, tBigNumber *resultado ) {
	If primernumero.signo==segundonumero.signo {
		resultado.signo=primernumero.signo;
		calcular(primernumero,segundonumero,1);
		If primernumero.tope>segundonumero.tope	
			*resultado.tope=primernumero.tope+1;
		else {
			If segundonumero.tope>primernumero.tope	
				*resultado.tope=segundonumero.tope+1;
			else
				*resultado.tope=primernumero.tope+1;
		}
	}
	else {
		If primernumero.tope>segundonumero.tope {
			*resultado.signo=primernumero.signo;
			*resultado.numero=calcular(primernumero,segundonumero,-1);
			*resultado.tope=primernumero.tope;
		}
		else {
			if primernumero.tope<segundonumero.tope {
				*resultado.signo=segundonumero.signo;
				*resultado.numero=calcular(segundonumero,primernumero,-1);
				*resultado.tope=segundonumero.tope;
				}
			else {
				*resultado.tope=primernumero.tope;
				If primernumero.numero[0]>segundonumero.numero[0] {
					*resultado.signo=primernumero.signo;
					*resultado.numero=calcular(primernumero,segundonumero,-1);
				}
				else {
					If primernumero.numero[0]<segundonumero.numero[0] {
						*resultado.signo=segundonumero.signo;
					*	resultado.numero=calcular(segundonumero,primernumero,-1);
					}
					else {
						*resultado.signo={1};
						*resultado.numero={0};
					}
				}
		}
	}

}

void multiplicacion (tBigNumber primernumero, tBigNumber segundonumero, tBigNumber *resultado) {
int i,j;

If primernumero.signo*segundonumero.signo>0
	*resultado.signo=1;
else
	*resultado.signo=-1;

*resultado.tope=primernumero.tope+segundonumero.tope
	
If primernumero.tope>segundonumero.tope 
	for i, primernumero.tope-1, 0, i-- {
		for j, segundonumero.tope-1, 0, j-- {
			resultado.numero[i+j]=primernumero.numero[i]*segundonumero.numero[j];
		}
	}
	for i, (primernumero.tope+segundonumero.tope), 1, i-- {
		resultado.numero[i-1]+=resultado.numero[i]-resultado.numero[i]%10
		resultado.numero[i]=resultado.numero[i]%10
	}
	
}


void printBigNumber (tBigNumber numero) {
	unsigned i;
	if (1 == numero.signo)
		printf("-");
	for (i = 0; i < numero.tope; ++i)
		printf("%d", numero.numero[i]);
	printf("\n");
}

int main (int argc, char *argv[]) {
	tBigNumber numeroA, numeroB, resultado;
	if (1 == numeroValido (argv[1]) && 1 == numeroValido (argv[2])) {
		charToBigNumber (argv[1], &numeroA);
		charToBigNumber (argv[2], &numeroB);
		calculo (numeroA, numeroB, &resultado, 1);
		printBigNumber (numeroA);
		printBigNumber (numeroB);
		printBigNumber (resultado);
	} else {
		printf("El numero ingresado no es valido.\n");
	}
	return 0;
}
