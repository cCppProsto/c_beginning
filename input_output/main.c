#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


/*
Неформатированный ввод/вывод
    fgetc, getc
    fgets
    fputc, putc
    fputs
    getchar
    gets(until C11)
    putchar
    puts
    ungetc

Форматированный ввод/вывод
    scanf,fscanf,sscanf
    vscanf,vfscanf,vsscanf
    printf,fprintf,sprintf,snprintf
    vprintf,vfprintf,vsprintf,vsnprintf
    wscanf,fwscanf,swscanf
    vwscanf,vfwscanf,vswscanf
    wprintf,fwprintf,swprintf
    vwprintf,vfwprintf,vswprintf

File positioning
    ftell       - returns the current file position indicator
    fgetpos     - gets the file position indicator
    fseek       - moves the file position indicator to a specific location in a file
    fsetpos     - moves the file position indicator to a specific location in a file
    rewind      - moves the file position indicator to the beginning in a file

Operations on files
    remove  - erases a file
    rename  - renames a file
    tmpfile - creates and opens a temporary, auto-removing file
    tmpnam  - returns a unique filename
*/


/*
Доступ к файлам
    fopen       - открытие файла
    fopen_s     - c11 открытие файла

    freopen     - переоткрытие существующего файла(потока) с другим именем
    freopen_s   - c11

    fclose  - закрытие файла
    fflush  - синхронизация потока вывода с текущим файлом

    fwide   - переключение файлового потока между wchar_t I/O и char I/O

    setbuf  - установка буфера для файлового потока
    setvbuf - установка буфера и его размера для файлового потока

Прямой ввод/вывод
    fread   - чтение с файла
    fwrite  - запись в файл
*/
//------------------------------------------------------------------------------
void input_output_a()
{
    //  tail -f test.txt + grep
    FILE    *pfile     = NULL;
    char    *testStr   = "input_output_a!\n";
    size_t  len         = strlen(testStr);

// открытие
    pfile = fopen("test.txt", "a+");

// запись (по умолчанию в буфер)
    fwrite(testStr, sizeof(char), len, pfile);

// сброс данных в буфере на диск
    fflush(pfile);

// запись (по умолчанию в буфер)
    fwrite(testStr, sizeof(char), len, pfile);
    fwrite(testStr, sizeof(char), len, pfile);

// закрытие
    fclose(pfile);
}
//------------------------------------------------------------------------------
void input_output_b()
{
    //  tail -f test.txt
    FILE    *pfile     = NULL;
    char    *testStr   = "input_output_b!\n";
    size_t  len         = strlen(testStr);

    // открытие
    pfile = fopen("test.txt", "a+");
    setbuf(pfile, NULL);

// запись
    fwrite(testStr, sizeof(char), len, pfile);
    fwrite(testStr, sizeof(char), len, pfile);
    fwrite(testStr, sizeof(char), len, pfile);
// закрытие
    fclose(pfile);
}
//------------------------------------------------------------------------------
// error
void input_output_c()
{
    //  tail -f test.txt
    FILE    *pfile      = NULL;
    char    buffer[10] = {0};
    char    *testStr    = "input_output_c!\n";
    size_t  len         = strlen(testStr);

    // открытие
    pfile = fopen("test.txt", "a+");
    setbuf(pfile, buffer);

// запись
    fwrite(testStr, sizeof(char), len, pfile);

// сброс данных в буфере на диск
    fflush(pfile);

// запись
    fwrite(testStr, sizeof(char), len, pfile);
    fflush(pfile);

    fwrite(testStr, sizeof(char), len, pfile);
    fflush(pfile);
// закрытие
    fclose(pfile);
}
//------------------------------------------------------------------------------
// error
void input_output_d()
{
    //  tail -f test.txt
    FILE    *pfile      = NULL;
    char    buffer[20] = {0};
    char    *testStr    = "input_output_d!\n";
    size_t  len         = strlen(testStr);

    // открытие
    pfile = fopen("test.txt", "a+");
    setbuf(pfile, buffer);

// запись и сброс данных в буфере на диск
    fwrite(testStr, sizeof(char), len, pfile);
    fwrite(testStr, sizeof(char), len, pfile);
    fwrite(testStr, sizeof(char), len, pfile);
    fflush(pfile);

// запись и сброс данных в буфере на диск
    fwrite(testStr, sizeof(char), len, pfile);
    fflush(pfile);

    fwrite(testStr, sizeof(char), len, pfile);
    fflush(pfile);
// закрытие
    fclose(pfile);
}
//------------------------------------------------------------------------------
// error
#define MY_BUF_SIZE 19
void input_output_e()
{
    //  tail -f test.txt
    FILE    *pfile              = NULL;
    char    buffer[MY_BUF_SIZE] = {0};
    char    *testStr            = "input_output_e!\n";
    size_t  len                 = strlen(testStr);

    // открытие
    pfile = fopen("test.txt", "a+");
    setvbuf(pfile, buffer, _IOFBF, MY_BUF_SIZE);

// запись и сброс данных в буфере на диск
    fwrite(testStr, sizeof(char), len, pfile);
    fwrite(testStr, sizeof(char), len, pfile);
    fwrite(testStr, sizeof(char), len, pfile);

    fflush(pfile);
    fwrite(testStr, sizeof(char), len, pfile);
    fwrite(testStr, sizeof(char), len, pfile);
// закрытие
    fclose(pfile);
}

//------------------------------------------------------------------------------
typedef struct
{
    int id;
    int value;
}sTest1;
typedef struct
{
    int id;
    char   *str;
}sTest2;
//------------------------------------------------------------------------------
void input_output_f()
{
    sTest1 datawrite;
    sTest1 dataread;
    datawrite.id    = 123;
    datawrite.value = 50987;

    FILE *pfwrite = NULL;
    FILE *pfread = NULL;

    pfwrite = fopen("save_data_1.data", "w");
    fwrite(&datawrite, sizeof(sTest1), 1, pfwrite);
    fclose(pfwrite);

    pfread = fopen("save_data_1.data", "r");
    fread(&dataread, sizeof(sTest1), 1, pfread);
    fclose(pfread);
}
//------------------------------------------------------------------------------
void input_output_g()
{
    sTest1 datawrite;
    sTest1 dataread;
    datawrite.id    = 123;
    datawrite.value = 50987;

    FILE *pfwrite = NULL;
    FILE *pfread = NULL;

    pfwrite = fopen("save_data_2.data", "w");
    fprintf(pfwrite, "%i\n%i", datawrite.id, datawrite.value);
    fclose(pfwrite);

    pfread = fopen("save_data_2.data", "r");
    fscanf(pfread, "%i\n%i", &dataread.id, &dataread.value);
    fclose(pfread);
}
//------------------------------------------------------------------------------
void input_output_h()
{
    sTest2 datawrite;
    sTest2 dataread;

    datawrite.id  = 123;
    datawrite.str = calloc(10, sizeof(char));
    strcpy(datawrite.str, "Hello\n");

    FILE *pfwrite = NULL;
    FILE *pfread = NULL;

    pfwrite = fopen("save_data_3.data", "w");
    fwrite(&datawrite, sizeof(sTest1), 1, pfwrite);
    fclose(pfwrite);
    free(datawrite.str);

    pfread = fopen("save_data_3.data", "r");
    fread(&dataread, sizeof(sTest1), 1, pfread);
    fclose(pfread);
}
//------------------------------------------------------------------------------
void input_output_i()
{
    sTest2 datawrite;
    sTest2 dataread;

    datawrite.id  = 123;
    datawrite.str = calloc(10, sizeof(char));
    strcpy(datawrite.str, "Hello\n");

    dataread.str = calloc(10, sizeof(char));

    FILE *pfwrite = NULL;
    FILE *pfread = NULL;

    pfwrite = fopen("save_data_4.data", "w");
    fprintf(pfwrite, "%i\n%s", datawrite.id, datawrite.str);
    fclose(pfwrite);
    free(datawrite.str);

    pfread = fopen("save_data_4.data", "r");
    fscanf(pfread, "%i\n%s", &dataread.id, dataread.str);
    fclose(pfread);
}
//------------------------------------------------------------------------------
void input_output_j()
{
    FILE *pfwrite = NULL;
    FILE *pfile = NULL;

    char    ch = 0;
    char    *testStr = "\n_%!32(_fgg\r=12ef1word$a123sdf(ka_stest\tend_of**OK\n";

    pfwrite = fopen("test_2.txt", "w");
    fprintf(pfwrite, "%s", testStr);
    fclose(pfwrite);

    pfile = fopen("test_2.txt", "r");
    while(1)
    {
        while((ch = fgetc(pfile)) != EOF)
        {
            if(isalpha(ch) || isdigit(ch))
            {
                ungetc(ch, pfile);
                break;
            }
        }

        if(ch == EOF)
            break;

        if(isalpha(ch))
        {
            while(isalpha(ch = fgetc(pfile)))
                putc(ch, stdout);
            ungetc(ch, pfile);
            putc('\n', stdout);
            continue;
        }
        if(isdigit(ch))
        {
            while(isdigit(ch = fgetc(pfile)))
                putc(ch, stdout);
            ungetc(ch, pfile);
            putc('\n', stdout);
            continue;
        }
    }
    fclose(pfile);
}
//------------------------------------------------------------------------------
void input_output_k()
{
    FILE *pfile = NULL;

    char buffer[1024] = {0};

    pfile = fopen("test_2.txt", "r");
    setbuf(pfile, buffer);
    fgetc(pfile);

    printf("%s\n", buffer);

    fclose(pfile);
}
//------------------------------------------------------------------------------
void input_output_l()
{
    // QMAKE_LFLAGS += -static-libgcc
    // ./t.exe < 1.txt  - file to stdin
    // ./t.exe > 1.txt  - stdout to file
    char buffer[1024] = {0};
    setbuf(stdin, buffer);
    fgetc(stdin);
    printf("%s\n", buffer);
}
//------------------------------------------------------------------------------
void input_output_m()
{
    size_t len = 0;
    char buffer[1024] = {0};
    len = fread(buffer, sizeof(char), 1024, stdin);
    printf("%i\n", len);
}


int main()
{
    //input_output_a();
    //input_output_b();
    //input_output_c(); // error  - Исправить ошибку
    //input_output_d(); // error - Исправить ошибку
    //input_output_e();

    //input_output_f();
    //input_output_g();

    //input_output_h();
    //input_output_i();

    //input_output_j();

    //input_output_k();
    input_output_l();
    //input_output_m();

    fprintf(stderr, "error");
    printf("info");

    // task
    // redirect stderr -> to file используя freopen
    return 0;
}
