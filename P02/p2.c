#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIN1 "T2_mucca_eh_burro.txt"
#define FIN2 "T2_ponce_eh_mais.txt"
#define FOUT "T2_leo_eh_pior.txt"

char **createStrArray(unsigned int word_total, unsigned int word_max_len, float *media, unsigned int *num_words);
unsigned int saveFile(char **words, unsigned int num_words, float media);
void freeStrArray(char **words, unsigned long int num_words);
FILE *openFile(const char *file, const char *mode);
static void die(const char *msg);

int main(void)
{
	unsigned int word_total, word_max_len, num_words, word_len, ret;
	float media;
	char **words;

	FILE *fin = openFile(FIN1, "r");
	if (!fin)
		die ("Não foi possível abrir o arquivo de entrada");

	fscanf(fin, "%u", &word_total);
	fscanf(fin, " %u", &word_max_len);
	fclose(fin);

	words = createStrArray(word_total, word_max_len, &media, &num_words);
	if (!words)
		die ("Não foi possível alocar conjunto de palavras");

	ret = saveFile(words, num_words, media);
	if (!ret)
		die("Não foi possível salvar palavras no arquivo");

	freeStrArray(words, num_words);

	return 0;
}

FILE *openFile(const char *file, const char *mode)
{
	return fopen(file, mode);
}

/* BOM, TEORICAMENTE JA TA FUNCIONANDO, SÓ ORGANIZAR DA FORMA RETARDADA QUE O ENUNCIADO QUER */

/* cala a boca, gaza */
char **createStrArray(unsigned int word_total, unsigned int word_max_len, float *media, unsigned int *num_words)
{
	unsigned long int word_len;
	char **words, *word;
	FILE *file;

	words = (char **)malloc(sizeof(char *) * (word_total));
	if (!words)
		return NULL;

	word = (char *)malloc(sizeof(char) * (word_max_len + 1));
	if (!word)
		return NULL;

	file = openFile(FIN2, "r");
	if (!file)
		return NULL;

	*num_words = 0;

	*media = 0;
	while(fscanf(file, " %s", word) == 1) {
		word_len = strlen(word);
		words[*num_words] = (char *)malloc(sizeof(char) * (word_len + 1));
		*media += word_len;
		strcpy(words[(*num_words)++], word);
	}

	fclose(file);

	*media /= *num_words;

	free(word);

	return words;
}


unsigned int saveFile(char **words, unsigned int num_words, float media)
{
	unsigned int i;
	FILE *fout = fopen(FOUT, "w");
	if (!fout)
		return 0;

	for (i = 0; i < num_words; ++i) {
		if (strlen(words[i]) > media)
			fprintf(fout, "%s\n", words[i]);
	}

	fclose(fout);
	return 1;
}

void freeStrArray(char **words, unsigned long int num_words)
{
	unsigned int i;
	for (int i = 0; i < num_words; ++i) {
		free(words[i]);
	}

	free(words);
}

/* SIM PONCE, EU TENHO UM CEREBRO E SEI USAR STATIC */
/* não é problema meu kekw */
static void die(const char *msg)
{
	fprintf(stderr, "ERRO: %s.\nAbortando programa.\n", msg);
	exit(1);
}

