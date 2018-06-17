#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#pragma warning( disable : 4996)
#define IN
#define OUT

typedef struct word_node {
	char content[50];
	int count;
	struct word_node *next;
}words, *pword;

typedef struct list_element {
	pword current_list;
	pword list_ptail;
}list,*plist;

void convert_Alpha_Signs(OUT FILE *save, char *buffer, FILE *fp);
void check_list(IN OUT pword *words_list, IN OUT pword *ptail, IN char cur_word[50]);
void add_to_list(IN OUT pword *words_list, IN OUT pword *ptail, IN char cur_word[50]);
void del_signs(IN OUT char *cur_word);
void convert_toLower_First(IN OUT char *cur_word);
void convert_toLower_After(IN OUT char *cur_word, IN int start_index);
void print_list(IN pword list, IN FILE *out_position);
void Getword_and_Search(IN OUT char *temp_word, IN char *source_p, IN int offset, IN plist vocabulary);

int main() {
	FILE *fp;
	fp = fopen("The_Holy_Bible_Test_Version.txt", "r+");
	char *buffer = (char *)malloc(1000);

	pword words_list = NULL;
	pword ptail = NULL;

	char temp_word[50] = {0};
	list vocabulary[26] = {0};
	
	char *word_head = NULL,*word_tail_space=NULL;

	short Flag_first_word = 0;

		int char_sum = 0,char_sum_without_Enter=0,word_sum=0,line_count=0;
	while (memset(buffer,0,sizeof(buffer)),fgets(buffer,256,fp)) {
		for (int i = 0; i < strlen(buffer); i++) {
			char_sum++;
			if (0==i && ((buffer[i + 1] >= 'a'&&buffer[i + 1] <= 'z') || (buffer[i + 1] >= 'A'&&buffer[i + 1] <= 'Z'))) {
				Flag_first_word = 1;
				continue;
			}
			if (buffer[i] == ' '||buffer[i]=='\t') {
				if (buffer[i+1]=='['||(buffer[i + 1] >='a'&&buffer[i + 1] <= 'z') || (buffer[i + 1] >= 'A'&&buffer[i + 1] <= 'Z')) {
					word_sum++;
					if (NULL == word_head) {
						word_head = buffer + i + 1;
						if (Flag_first_word) {
							Getword_and_Search(temp_word,buffer,i,vocabulary);

							word_head = NULL;
							i--;
							char_sum--;
							Flag_first_word = 0;
						}
						continue;
					}
					else {
						word_tail_space = buffer + i;
						Getword_and_Search(temp_word, word_head, word_tail_space-word_head, vocabulary);
						word_head = NULL;
						word_tail_space = NULL;
						i--;
						char_sum--;
						word_sum--;
						continue;
					}
				}
			}
			if (buffer[i] == '\n') {
				line_count++;
				if (NULL != word_head) {
					Getword_and_Search(temp_word, word_head, buffer+i - word_head, vocabulary);
					word_head = NULL;
				}
				if (Flag_first_word) {
					word_sum++;
					Getword_and_Search(temp_word, buffer, i, vocabulary);
				}
			}
		}
		fprintf(stdout, "%s", buffer);
		//printf("char_sum=%d char_sum_without_Enter=%d word_sum=%d line_count=%d", char_sum, char_sum-line_count,word_sum, line_count);
		//system("pause");
	}
	free(buffer);
	buffer = NULL;
	//printf("char_sum=%d char_sum_without_Enter=%d word_sum=%d line_count=%d", char_sum, char_sum - line_count, word_sum, line_count);
	
	FILE *record = fopen("Records.txt", "r+");
	//for (pword pcur=vocabulary[0].current_list;NULL!=pcur;pcur=pcur->next) {
	//	fprintf(record, "%s\n", pcur->content);
	//}
	for (int i=0;i<26;i++) {
		fprintf(record,"[%c]\n",(char)(i + 65));
		print_list(vocabulary[i].current_list, record);
		fprintf(record, "\n\n");
	}
	fclose(fp);
	fclose(record);

	system("pause");
}

void check_list(IN OUT pword *words_list,IN OUT pword *ptail,IN char cur_word[50]) {
	if (0==strcmp(cur_word, "")) return;
	if (NULL == (*words_list)) {
		add_to_list(words_list,ptail,cur_word);
		return;
	}
	short is_exist = 1;
	for (pword pcur = *words_list;NULL!=pcur;pcur=pcur->next) {
		if (0==strcmp(pcur->content, cur_word)) {
			pcur->count++;
			return;
		}
	}
	add_to_list(words_list, ptail, cur_word);
}

void add_to_list(IN OUT pword *words_list,IN OUT pword *ptail,IN char cur_word[50]) {
	pword new_word = (pword)malloc(sizeof(words));
	memset(new_word, 0, sizeof(words));
	strcpy(new_word->content, cur_word);
	new_word->count = 1;
	
	if (NULL == *words_list) {
		*words_list = new_word;
		*ptail = new_word;
	}else {
		(*ptail)->next = new_word;
		*ptail = new_word;
	}
}

void del_signs(IN OUT char *cur_word) {
	if ((cur_word[0]>'Z'&&cur_word[0]<'a')||cur_word[0]<'A'||cur_word[0]>'z') {
		memmove(cur_word, cur_word + 1, strlen(cur_word));
	}
	int len = strlen(cur_word);
	for (int i=len-1; i>=0&&((cur_word[i]>'Z'&&cur_word[i]<'a') || cur_word[i]<'A' || cur_word[i]>'z');i--) {
		cur_word[i] = 0;
	}
}

void convert_toLower_First(IN OUT char *cur_word) {
	if (cur_word[0] >= 'A'&&cur_word[0] <= 'Z') {
		cur_word[0] = tolower(cur_word[0]);
	}
	if(cur_word[1] >= 'A'&&cur_word[1] <= 'Z'){
		convert_toLower_After(cur_word, 1);
	}
}
void convert_toLower_After(IN OUT char *cur_word,IN int start_index) {
	for (int i = start_index; i < strlen(cur_word); i++) {
		if (cur_word[i] >= 'A'&&cur_word[i] <= 'Z') {
			cur_word[i] = tolower(cur_word[i]);
		}else {
			continue;
		}
	}
}

void print_list(IN pword list,IN FILE *out_position) {
	for (pword pcur=list;NULL!=pcur;pcur=pcur->next) {
		fprintf(out_position, "%s : %d\n", pcur->content, pcur->count);
	}
}

void Getword_and_Search(IN OUT char *temp_word,IN char *source_p,IN int offset, IN plist vocabulary) {
	strncpy(temp_word, source_p, offset);
	temp_word[offset] = 0;

	del_signs(temp_word);
	convert_toLower_First(temp_word);
	check_list(&(vocabulary[temp_word[0] - 97].current_list), &(vocabulary[temp_word[0] - 97].list_ptail), temp_word);

	memset(temp_word, 0, sizeof(temp_word));
}