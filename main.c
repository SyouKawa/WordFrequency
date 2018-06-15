#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning( disable : 4996)
#define IN
#define OUT

typedef struct word_node {
	char content[50];
	int count;
	struct word_node *next;
}words, *pword;

void check_list(IN OUT pword *words_list, IN OUT pword *ptail, IN char cur_word[50]);
void add_to_list(IN OUT pword *words_list, IN OUT pword *ptail, IN char cur_word[50]);
void del_signs(IN OUT char *cur_word);

int main() {
	FILE *fp,*save;
	fp = fopen("The_Holy_Bible_Test_Version.txt", "r+");
	char *buffer = (char *)malloc(1000);

	pword words_list = NULL;
	pword ptail = NULL;
	
	char *word_head = NULL,*word_tail_space=NULL;

	char temp_word[50] = {0};

	short Flag_first_word = 0;

	int char_sum = 0,char_sum_without_Enter=0,word_sum=0,line_count=0;
	while (memset(buffer,0,sizeof(buffer)),fgets(buffer,256,fp)) {
		for (int i = 0; i < strlen(buffer); i++) {
			char_sum++;
			if (0==i && ((buffer[i + 1] >= 'a'&&buffer[i + 1] <= 'z') || (buffer[i + 1] >= 'A'&&buffer[i + 1] <= 'Z'))) {
				word_sum++;
				Flag_first_word = 1;
				continue;
			}
			if (buffer[i] == ' '||buffer[i]=='\t') {
				if (buffer[i+1]=='['||(buffer[i + 1] >='a'&&buffer[i + 1] <= 'z') || (buffer[i + 1] >= 'A'&&buffer[i + 1] <= 'Z')) {
					if(!Flag_first_word) word_sum++;
					if (NULL == word_head) {
						word_head = buffer + i + 1;
						if (Flag_first_word) {
							strncpy(temp_word,buffer,i);
							temp_word[i] = 0;

							del_signs(temp_word);
							check_list(&words_list, &ptail, temp_word);

							word_head = NULL;
							i--;
							char_sum--;
							memset(temp_word, 0, sizeof(temp_word));
							Flag_first_word = 0;
						}
						continue;
					}
					else {
						word_tail_space = buffer + i;
						strncpy(temp_word, word_head, word_tail_space - word_head);
						temp_word[word_tail_space - word_head] = 0;

						del_signs(temp_word);
						check_list(&words_list, &ptail, temp_word);

						word_head = NULL;
						word_tail_space = NULL;
						i--;
						char_sum--;
						word_sum--;
						memset(temp_word,0,sizeof(temp_word));
						continue;
					}
				}
			}
			if (buffer[i] == '\n') {
				line_count++;
				if (NULL != word_head) {
					strncpy(temp_word, word_head, buffer + i - word_head);
					temp_word[buffer + i - word_head] = 0;

					del_signs(temp_word);
					check_list(&words_list, &ptail, temp_word);

					word_head = NULL;
					
					memset(temp_word, 0, sizeof(temp_word));
				}
				if (Flag_first_word) {
					word_sum++;
					strncpy(temp_word, buffer, i);
					temp_word[i] = 0;

					del_signs(temp_word);
					check_list(&words_list, &ptail, temp_word);
					
					memset(temp_word, 0, sizeof(temp_word));
				}
			}
		}
		fprintf(stdout, "%s", buffer);
		//printf("char_sum=%d char_sum_without_Enter=%d word_sum=%d line_count=%d", char_sum, char_sum-line_count,word_sum, line_count);
		//system("pause");
	}
	free(buffer);
	buffer = NULL;
	printf("char_sum=%d char_sum_without_Enter=%d word_sum=%d line_count=%d", char_sum, char_sum - line_count, word_sum, line_count);
	
	FILE *record = fopen("Records.txt", "r+");
	for (pword pcur=words_list;NULL!=pcur;pcur=pcur->next) {
		fprintf(record, "%s\n", pcur->content);
	}
	fclose(fp);
	fclose(save);
	fclose(record);
	
	system("pause");
}

void check_list(IN OUT pword *words_list,IN OUT pword *ptail,IN char cur_word[50]) {
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
	
	//尾插
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
	/*if ((cur_word[len-1]>'Z'&&cur_word[len-1]<'a') || cur_word[len-1]<'A' || cur_word[len-1]>'z') {
		cur_word[len - 1] = 0;
	}*/
}