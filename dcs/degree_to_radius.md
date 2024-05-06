# Conversao de Angulos em graus para Radianos
```c
/*
  Conversao de Angulos em graus para Radianos
  Calcular seno, coseno e tangente
  Obs: Geralmente na programacao utilizamos 
  angulos em formato de radiano
*/
int	main(void)
{
	float	angulo, confere;
	float	seno, coseno, tangente;

	printf("Digite uma angulo em graus: ");
	scanf("%f", &angulo);
	/*
	 Conversao de graus em radianos
	 180˚ e igual a PI radianos
	 angulo˚ e igual a X radianos
	 formula:
		X = ang˚*PI/180
	*/
	angulo = (angulo * M_PI) / 180;
	seno = sin(angulo);
	coseno = cos(angulo);
	tangente = tan(angulo);
	printf("\n\tANGULO EM RADIANOS = %f", angulo);
	printf("\n\tSENO = %f\n\tCOSENO = %f\n\tTANGENTE = %f",\
			seno, coseno, tangente);
	// sen^2(x) + cos^2(x) = 1
	confere = pow(seno, 2) + pow(coseno, 2);
	printf("\n\tCONFERENCIA  = %f\n", confere);
	return (0);
}
```