void crearBNknotope (tBigNumber bignumero, tBigNumber *notope) {
	(*notope).tope=bignumero.tope-1;
	(*notope).signo=1
	(*notope).numero[]=bignumero.numero;
}

void crearBNktope (tBigNumber bignumero, tBigNumber *lodeltope) {
	(*lodeltope).tope=bignumero.tope;
	(*lodeltope).signo=1;
	(*lodeltope).numero[]={0};
	(*lodeltope).numero[tope]=bignumero.numero[tope];
}

void karatsuba (tBigNumber primernumero, tBigNumber segundonumero, tBigNumber *preresultado) {
	tBigNumber lodeltope1, lodeltope2, notope1, notope2, sitope, multcruzada1, multcruzada2, resulttopes, resulcruza, parteNoK;
	crearBNktope(primernumero, lodeltope1);
	crearBNktope(segundonumero, lodeltope2);
	crearBNknotope(primernumero, notope1);
	crearBNknotope(segundonumero, notope2);
	multiplicacion (lodeltope1, lodeltope2, sitope);
	multiplicacion (lodeltope1, notope2, multcruzada1);
	multiplicacion (lodeltope2, notope1, multcruzada2);
	suma(multcruzada1, multcruzada2, resulcruza);
	resulcruza.tope=resulcruza.tope+1;
	resulcruza.numero[tope]=0;
	suma(resulcruza, sitope, parteNoK);
	(*preresultado).numero=
	If (primernumero.tope)!=1 || (segundonumero.tope)!=1 {
		karatsuba(notope1, notope2, preresultado);
		suma(parteNoK, preresultado, preresultado);
	}
	else {
		(*preresultado)=parteNoK
	}
}

void multiplcacionk (tBigNumber primernumero, tBigNumber segundonumero, tBigNumber *resultado) {
	
	karatsuba(primernumero, segundonumero, resultado);
	resultado.tope=(primernumero.tope)+(segundonumero.tope);
	If (primernumero.signo)==(segundonumero.signo) 
		(*resultado).signo=1;
	else
		(*resultado).signo=-1;
		
}
