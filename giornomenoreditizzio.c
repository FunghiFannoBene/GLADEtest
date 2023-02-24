void menoreditizzio(int **giorni)
{
	int i;
	i=0; //giorno da 1 a 7 lun mar mer gio ven sab dom
	int x;
	x = 0; //quantità di settimane
	int* giornisett;
	giornisett = malloc(sizeof(int)*7);
	int complessivo;

	while(i < 7)
	{
		while(x < 4)
		{
			giornisett[i] += giorni[x][i];
			x++;
		}
		x=0;
		i++;
	}printf("la media dei giorni della settimana durante 28 giorni è \n lunedi:%d \n martedì:%d \n mercoledì: %d \n giovedì: %d \n venerdì %d \n sabato: %d \n domenica: %d \n",
	 giornisett[0],giornisett[1],giornisett[2],giornisett[3],giornisett[4],giornisett[5],giornisett[6]);
	complessivo = giornisett[0]+giornisett[1]+giornisett[2]+giornisett[3]+giornisett[4]+giornisett[5]+giornisett[6];
	// printf("Complessivo di: %d", complessivo);
	// i=0;
	// while(i < 7)
	// {
	// 	giornisett[i] /= 4;
	// 	i++;
	// }
	// printf("la media dei giorni della settimana durante 28 giorni è \n lunedi:%d \n martedì:%d \n mercoledì: %d \n giovedì: %d \n venerdì %d \n sabato: %d \n domenica: %d \n",
	//  giornisett[0],giornisett[1],giornisett[2],giornisett[3],giornisett[4],giornisett[5],giornisett[6]);
}