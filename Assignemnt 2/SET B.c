Set B -

a)	Read the data from “Student.txt (Stud_name, Age, Percentage)” file and sort on Stud_name using bubble sort.(Create a separate sorted file).

#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float percentage;
};

int main() {
    FILE *fp, *out;
    struct Student s[100], temp;

    fp = fopen("Student.txt", "r");
    if (fp  ==  NULL) {
        printf("Error opening file!\n");
        return 1;
    }

      Int n = 0
    // Read students from file
    while (fscanf(fp, "%s %d %f", s[n].name, &s[n].age, &s[n].percentage) != EOF)           {
        n++;
    }
    fclose(fp);

    // Bubble Sort on name
    for (int i = 0;  i < n - 1;  i++) {
        for (int j = 0;  j < n - i - 1;  j++) {
            if (strcmp(s[j].name,  s[j + 1].name)  >  0) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    // Write sorted data in file 
    out = fopen("SortedByName.txt", "w");
    for (int i = 0;  i < n;  i++) {
        fprintf(out, "%s %d %.2f\n", s[i].name, s[i].age, s[i].percentage);
    }

    fclose(out);

    printf("Sorted by Name using Bubble Sort -> SortedByName.txt \n");
    return 0;
}


b) Read the data from “Student.txt (Stud_name, Age, Percentage)” file and sort on Age using
insertion sort. (Create a separate sorted file).

#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float percentage;
};

int main() {
    FILE  *fp,  *out;
    struct Student s[100];

    fp = fopen("Student.txt", "r");
    if (fp  ==  NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int n = 0;
    while (fscanf(fp, "%s %d %f", s[n].name, &s[n].age, &s[n].percentage) != EOF) {
        n++;
    }
    fclose(fp);

    // Insertion Sort on age
    for (int i = 1;  i < n;  i++) {
        int curr = s[i];
        int j = i - 1;
        while (j >= 0 &&  s[j].age > curr.age) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = curr;
    }

    out = fopen("SortedByAge.txt",  "w");
    for (int i = 0;  i < n;   i++) {
        fprintf(out, "%s %d %.2f\n",  s[i].name,  s[i].age,  s[i].percentage);
    }
    fclose(out);

    printf("Sorted by Age using Insertion Sort -> SortedByAge.txt\n");
    return 0;
}


c)	Read the data from “Student.txt (Stud_name, Age, Percentage)” file and sort on Percentage using selection sort.(Create a separate sorted file).

#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float percentage;
};

int main() {
    FILE *fp, *out;
    struct Student s[100], temp;

    fp = fopen("Student.txt",  "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }


    int n = 0
    while (fscanf(fp, "%s %d %f", s[n].name,  &s[n].age,   &s[n].percentage) != EOF) {
        n++;
    }
    fclose(fp);

    // Selection Sort on percentage
    for (int  i = 0;   i < n - 1;   i++) {
        int min_idx = i;
        for (int  j = i + 1;  j < n;  j++) {
            if (s[j].percentage  <  s[min_idx].percentage) {
                min_idx = j;
            }
        }
        if (min_idx !=  i) {
            temp = s[i];
            s[i] = s[min_idx];
            s[min_idx] = temp;
        }
    }

    out = fopen("SortedByPercentage.txt",  "w");
    for (int i = 0;   i < n;   i++) {
        fprintf(out, "%s %d %.2f\n",  s[i].name,  s[i].age,  s[i].percentage);
    }
    fclose(out);

    printf("Sorted by Percentage using Selection Sort ->  SortedByPercentage.txt\n");
    return 0;
}


