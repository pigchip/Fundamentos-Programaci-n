#include<stdio.h>//Libreria
//Declaracion de variables
int i,j,k,l,m,o;//Contadores
int car,a,b,c,x,palabras,caracteres,numlineas,enteros,flotantes;//Variables
char lineas[4200];//Guarda la parte del argv[2] d1_d2_d3...
char num[600][6];//Guarda los numeros d1,d2,d3... Hasta 600 de 6 cifras
char lineasParr[10000][1000];//Guarda las filas del texto Hasta a 10,000 filas con 1000 caracteres cada una
char buscar[100];//Guarda la cadena de CC, CP y CS 
char palabrasParr[1000][1000];//Guarda todas las palabras del texto Hasta 1000 de 1000 caracteres
char enterosParr[1000][1000];//Guarda todas las enteros del texto Hasta 1000 de 1000 caracteres
char palabrasLinea[1000][1000][100];//Guarda las palabras por linea [linea][palabra][caracter]
FILE *ent;
//Funciones
void d1_d2_d3(int l,char *argv[]);//Guarda d1,d2,d3... en num[i][j]
void guardafilas();//Guarda todas las filas en lineasParr[i][j]
int entero();//Obtiene los valores de d1_d2_d3.. en int
void pal();//Guarda las todas las palabras en palabrasParr[i][j]
void palin();//Guarda las palabras por linea en palabrasLinea[i][j][k]
//Función principal
int main(int argc,char *argv[])//Inicio del programa
{
	FILE *sal;
	ent =fopen(argv[1],"r");
	sal =fopen(argv[3],"w");
	if(argv[2][0]=='L'&&argv[2][1]=='_')//Atributo "L" (Imprime lineas indicadas por separador de digitos)
	{
		l=2;
		d1_d2_d3(l,argv);
		guardafilas();
		//*Inicia parte de obtener los numeros d1,d2,d3 en forma de enteros (int)*
		for(k=0;num[k][0]!='\0';k=k+1)//Leer cada cadena num[i]
		{
			entero();
			fprintf(sal,"%s",lineasParr[c-1]);//Imprime solo las filas deseadas
		}
		printf("Operacion realizada");
	}
	else
	{
		if(argv[2][0]=='C'&&argv[2][1]=='_')//Atributo "C" (Imprime solo las columnas que se indiquen)
		{
			l=2;
			d1_d2_d3(l,argv);
			guardafilas();
			pal();
			palin();
			for(i=0;lineasParr[i][0]!='\0';i=i+1)
			{
				//*Inicia parte de obtener los numeros d1,d2,d3 en forma de enteros (int)*
				for(k=0;num[k][0]!='\0';k=k+1)//Leer cada cadena num[i]
				{
					entero();
					fprintf(sal,"%s",palabrasLinea[i][c-1]);//Imprime solo las filas deseadas
				}
				if(lineasParr[i+1][0]!='\0')
					fprintf(sal,"\n");					
			}
			printf("Operacion realizada");
		}	
		else
		{
			if(argv[2][0]=='I'&&argv[2][1]=='L')//Atributo "IL" (Da un salto de linea a las filas que se le indiquen)
			{
				l=3;
				d1_d2_d3(l,argv);
				guardafilas();
				for(i=0;lineasParr[i][0]!='\0';i=i+1)
				{
					//*Inicia parte de obtener los numeros d1,d2,d3 en forma de enteros (int)*
					for(k=0;num[k][0]!='\0';k=k+1)//Leer cada cadena[i]
					{
						entero();
						if(i+1==c)
							fprintf(sal,"\n");							
					}
					fprintf(sal,"%s",lineasParr[i]);//Imprime el texto 
				}
				printf("Operacion realizada");
			}
			else
			{
				if(argv[2][0]=='I'&&argv[2][1]=='C')//Atributo "IC" (Da un tabulador a las filas que se le indiquen)
				{
					l=3;
					d1_d2_d3(l,argv);
					guardafilas();
					for(i=0;lineasParr[i][0]!='\0';i=i+1)
					{
						//*Inicia parte de obtener los numeros d1,d2,d3 en forma de enteros (int)*
						for(k=0;num[k][0]!='\0';k=k+1)//Leer cada cadena[i]
						{
							entero();
							if(i+1==c)
								fprintf(sal,"	");						
						}
						fprintf(sal,"%s",lineasParr[i]);//Imprime el texto 
					}
					printf("Operacion realizada");
				}
				else
				{
					if(argv[2][0]=='C'&&argv[2][1]=='C'&&argv[2][2]=='_')//Atributo "CC" (Busca cuantas veces se repite una cadena dada)
					{	
						//*Inicia parte de obtener cadena*
						j=0;
						for(i=3;argv[2][i]!='\0';i=i+1)
						{
							buscar[j]=argv[2][i];		
							j=j+1;	
						}//Guarda en buscar[j] la cadena
						buscar[j]=10;
						//*Termina parte de obtener cadena*			
						guardafilas();
						pal();						
						m=0;
						k=0;
						l=0;
						for(i=0;palabrasParr[i][0]!='\0';i=i+1)
						{
							for(j=0;palabrasParr[i][j]!='\0';j=j+1)
							{
								k=k+1;
								if(buscar[j]==palabrasParr[i][j])
									l=l+1;														
							}
							if(k==l)
							m=m+1;
							k=0;
							l=0;
						}											
						fprintf(sal,"La cadena:%sse repite %d veces en el texto",buscar,m);	
						printf("Operacion realizada");	
					}
					else
					{
						if(argv[2][0]=='C'&&argv[2][1]=='P')//Atributo "CP" (Busca cuantas veces se repite un prefijo dado)
						{
							//*Inicia parte de obtener cadena*
							j=0;
							for(i=3;argv[2][i]!='\0';i=i+1)
							{
								buscar[j]=argv[2][i];		
								j=j+1;	
							}//Guarda en buscar[j] la cadena
							//*Termina parte de obtener cadena*			
							guardafilas();							
							pal();
							m=0;
							k=0;
							l=0;
							for(i=0;palabrasParr[i][0]!='\0';i=i+1)
							{
								for(j=0;buscar[j]!='\0';j=j+1)
								{			
									k=k+1;						
									if(buscar[j]==palabrasParr[i][j])
									l=l+1;				
								}
								if(l==k)
								m=m+1;
								k=0;
								l=0;
							}											
							fprintf(sal,"El prefijo:%s\nse repite %d veces en el texto",buscar,m);		
							printf("Operacion realizada");																	
						}
						else
						{
							if(argv[2][0]=='C'&&argv[2][1]=='S')//Atributo "CS" (Busca cuantas veces se repite un sufijo dado)
							{
								//*Inicia parte de obtener cadena*
								j=0;
								for(i=3;argv[2][i]!='\0';i=i+1)
								{
									buscar[j]=argv[2][i];
									j=j+1;
								}//Guarda en buscar[j] la cadena
								buscar[j]=10;
								//*Termina parte de obtener cadena*			
								o=0;
								for(i=0;buscar[i]!='\0';i=i+1)
								o=o+1;
																
								guardafilas();							
								pal();
								
								k=0;
								l=0;
								m=0;
								for(i=0;palabrasParr[i][0]!='\0';i=i+1)
								{
									for(j=0;palabrasParr[i][j]!='\0';j=j+1)
									{
										if(buscar[m]==palabrasParr[i][j]&&buscar[m+1]==palabrasParr[i][j+1])
										{
											m=m+1;					
										}
										if(buscar[m]==palabrasParr[i][j]&&buscar[m+1]!=palabrasParr[i][j+1])
										{
											m=0;
										}
									}
									if(m==o)
									k=k+1;	
									m=0;
								}																		
								fprintf(sal,"El sufijo:%sse repite %d veces en el texto",buscar,k);	
								printf("Operacion realizada");								
							}
							else
							{
								if(argv[2][0]=='W'&&argv[2][1]=='C')//Atributo "WC" (Cuenta cadenas, caracteres y número de lineas)
								{
									guardafilas();
									pal();
									palabras=0;
									for(i=0;palabrasParr[i][0]!='\0';i=i+1)
										palabras=palabras+1;
									fprintf(sal,"El numero de cadenas es: %d\n",palabras);
									for(i=0;lineasParr[i][0]!='\0';i=i+1)
										numlineas=numlineas+1;
									fprintf(sal,"El numero de caracteres es: %d\n",caracteres);
									fprintf(sal,"El numero de lineas es: %d",numlineas);	
									printf("Operacion realizada");									
								}
								else
								{
									if(argv[2][0]=='W'&&argv[2][1]=='N'&&argv[2][2]=='U'&&argv[2][3]=='M')//Atributo "WNUM" (Cuentas números enteros y flotantes)
									{
										guardafilas();
										pal();
										k=0;
										l=0;
										enteros=0;
										flotantes=0;
										for(i=0;palabrasParr[i][0]!='\0';i=i+1)
										{
											for(j=0;palabrasParr[i][j]!='\0';j=j+1)
											{
												if((palabrasParr[i][j-1]>=48&&palabrasParr[i][j-1]<=57)&&(palabrasParr[i][j]=='.')&&(palabrasParr[i][j+1]>=48&&palabrasParr[i][j+1]<=57))
												{
													flotantes=flotantes+1;
													i=i+1;
													j=0;
												}	
											}
												for(j=0;palabrasParr[i][j]!='\0';j=j+1)
												enterosParr[l][j]=palabrasParr[i][j];
												l=l+1;																													
										}	
										
										i=0;
										j=0;
										for(i=0;enterosParr[i][0]!='\0';i=i+1)
										{
											for(j=0;enterosParr[i][j]!='\0';j=j+1)
											{
												if(enterosParr[i][j]>=48&&enterosParr[i][j]<=57)
												{
													enteros=enteros+1;
													enterosParr[i][j+1]='\0';
												}
											}																									
										}									
																
											fprintf(sal,"El numero de flotantes es: %d",flotantes);
											fprintf(sal,"\nEl numero de enteros es: %d",enteros);
											printf("Operacion realizada");																															
									}
									else 
									{
										if(argv[2][0]=='I'&&argv[2][1]=='N'&&argv[2][2]=='C')//Atributo "INC" (Numera filas)
										{
											guardafilas();
											for(k=0;lineasParr[k][0]!='\0';k=k+1)
											{
												fprintf(sal,"%d.-%s",k+1,lineasParr[k]);													
											}
											printf("Operacion realizada");
										}
										else
											printf("Error de sintaxis");
									}
								}
							}
						}
					}
				}
			}		
		}
	}
	fclose(ent);
	fclose(sal);
	return 0;
}
//Funciones
void d1_d2_d3(int l,char *argv[])//Guarda d1,d2,d3... en num[i][j] 
{
	//*Inicia parte de obtener d1,d2,d3...*
	j=0;
	for(i=l;argv[2][i]!='\0';i=i+1)
	{
	if(argv[2][i]!='d')
		{
			lineas[j]=argv[2][i];
			j=j+1;		
		}
	}//Guarda en lineas[j] la parte d1_d2_d3...
	j=0;
	k=0;
	for(i=0;lineas[i]!='\0';i=i+1)
	{
		if(lineas[i]!='_')
		{
			num[j][k]=lineas[i];
			k=k+1;
		}
		else
		{
			j=j+1;
			k=0;
		}
	}//Guarda en num[j][k] los numeros d1,d2,d3...
	//*Termina parte de obtener d1,d2,d3...*
}

void guardafilas()//Guarda todas las filas en lineasParr[i][j] 
{
	//*Inicia parte de guardar filas*
	i=0;
	k=0;
	j=0;	
	while ((car = getc(ent)) != EOF)
	{
		caracteres=caracteres+1;

		if(car==10)//Si el caracter es un salto de linea lo guardamos y cambiamos a otra cadena
		{
			lineasParr[k][j]=10;
			k=k+1;
			j=0;
		}
		else //Si el caracter no es un salto de linea lo guardamos y avanzamos la siguiente posicion
		{
			lineasParr[k][j]=car;
			j=j+1;
		}
	}
	//*Termina parte de guardar filas
}

int entero()//Obtiene los valores de d1_d2_d3.. en int
{
	l=0;
	x=num[k][l];
	a=x-48;
	l=l+1;
	if(num[k][l]!='\0')
	{
		x=num[k][l];
		b=x-48;
		l=l+1;
		if(num[k][l]!='\0')
		{
			x=num[k][l];
			c=x-48;
			b=b*10;
			a=a*100;
			c=a+b+c;
		}
		else
		{
			a=a*10;
			c=a+b;
		}	
	}
	else
		c=a;//*Termina parte de obtener los numeros d1,d2,d3 en forma de enteros (int)*	
	return c;
}

void pal()//Guarda las todas las palabras en palabrasParr[i][j]
{
	k=0;
	j=0;
	for(i=0;lineasParr[i][0]!='\0';i=i+1)//Leer cada caracter
	{
		for(l=0;lineasParr[i][l]!='\0';l=l+1)//Guardamos cada cadena
		{
			if(lineasParr[i][l]==' ')
			{
				if(lineasParr[i][l+1]!=' '&&lineasParr[i][l+1]!=10&&lineasParr[i][l+1]!='	'&&lineasParr[i][l+1]!='\0'&&lineasParr[i][l+2]!=' '&&lineasParr[i][l+2]!=10)
				{
					l=l+1;
					palabrasParr[j][k]=lineasParr[i][l];
					k=k+1;
				}
			}
			else
			{
				if(lineasParr[i][l]!=10&&lineasParr[i][l]!='	'&&lineasParr[i][l]!=' ')
				{
					palabrasParr[j][k]=lineasParr[i][l];
					k=k+1;
					if(lineasParr[i][l+1]==' ')
					{
						palabrasParr[j][k]=10;
						j=j+1;
						k=0;																			
					}
					if(lineasParr[i][l+1]==10)
					{
						palabrasParr[j][k]=10;
						j=j+1;
						k=0;																																
					}
					if(lineasParr[i][l+1]=='	')
					{
						palabrasParr[j][k]=10;
						j=j+1;
						k=0;																							
					}	
					if(lineasParr[i][l+1]=='\0')
					{
						palabrasParr[j][k]=10;
						j=j+1;
						k=0;																							
					}																																	
				}
				if(lineasParr[i][l]=='	'&&lineasParr[i][l-1]!=10&&lineasParr[i][l-1]!='	'&&lineasParr[i][l-1]!=' '&&lineasParr[i][l-2]==' ')
				{
					palabrasParr[j][k]=10;
					j=j+1;
					k=0;					
				}	
			
			}
		}
	}	
}

void palin()//Guarda las palabras por linea en palabrasLinea[i][j][k]
{
	o=0;
	for(i=0;lineasParr[i][0]!='\0';i=i+1)//Avanzamos fila por fila
	{
		k=0;
		o=0;
		for(j=0;lineasParr[i][j]!='\0';j=j+1)//Guardamos las palabras
		{
			if(lineasParr[i][j]==10)
			{
				lineasParr[i][j]=' ';
			}

			if(lineasParr[i][j]!=' ')
			{
				palabrasLinea[i][o][k]=lineasParr[i][j];
				k=k+1;
			}
			else
			{
				if(lineasParr[i][j]==' ')
				{
					palabrasLinea[i][o][k]=' ';
					k=0;
					o=o+1;
				}
			}
		}
	}
}
