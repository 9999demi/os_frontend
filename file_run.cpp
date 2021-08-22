#include "file_system.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "file_run.h"

void run()
{
    init_system();

    init_root_dir();

    printf("Terminal [Version 0.0.0.1]\n"
           "(c) 2020 CSC3002 Group 48 Project\n"
           "All Rights Reserved\n"
           "\n");

    char input_command[100];
//    char user_name[100] = "Super User";
    printf("TheOS\\>");

    scanf("%s", input_command);

    while(strcmp(input_command, "quit") != 0){
        if(strcmp(input_command, "help") == 0){
            help();
        }else if(strcmp(input_command, "cd") == 0){
            char dir_name[100];
            scanf("%s", dir_name);
            change_dir(dir_name);
        }else if(strcmp(input_command, "ls") == 0){
            show_dir();
        }else if(strcmp(input_command, "pwd") == 0){
            printf("%s\n", get_path());
        }else if(strcmp(input_command, "mkdir") == 0){
            char dir_name[100];
            scanf("%s", dir_name);
            create_dir(dir_name);
        }else if(strcmp(input_command, "rmdir") == 0){
            char dir_name[100];
            scanf("%s", dir_name);
            delete_dir(dir_name);
        }else if(strcmp(input_command, "mv") == 0){
            char old_dir_name[100], new_dir_name[100];
            scanf("%s", old_dir_name);
            scanf("%s", new_dir_name);

            change_name(old_dir_name, new_dir_name);
        }else if(strcmp(input_command, "touch") == 0){
            char file_name[100];
            int file_size;

            scanf("%s", file_name);
            scanf("%d", &file_size);
            create_file(file_name, file_size);
        }else if(strcmp(input_command, "rm") == 0){
            char file_name[100];
            scanf("%s", file_name);

            delete_file(file_name);
        }else if(strcmp(input_command, "read") == 0){
            char file_name[100];
            int length;
            scanf("%s", file_name);
            scanf("%d", &length);

            read(file_name, length);
        }else if(strcmp(input_command, "reread") == 0){ //read again from the beginning
            char file_name[100];
            int length;
            scanf("%s", file_name);
            scanf("%d", &length);

            reread(file_name, length);
        }else if(strcmp(input_command, "write") == 0){
            char file_name[100];
            char content[1024];
            scanf("%s", file_name);
            scanf("%1024[0-9|a-z|A-Z/ -?\"'./,~!@#$%^&*()+_=;]", content);

            char tmp[1024];
            for(int i = 1; i < 1024; i++){
                tmp[i-1] = content[i];
            }

            write(file_name, tmp);
        }else if(strcmp(input_command, "rewrite") == 0){
            char file_name[100];
            char content[1024];
            scanf("%s", file_name);
            scanf("%s", content);

            rewrite(file_name, content);
        }else if(strcmp(input_command, "cat") == 0){
            char file_name[100];
            scanf("%s", file_name);

            read_all(file_name);
        }else{
            printf("Command Not Found. Enter \"help\" If Needed!\n");
        }

        printf("TheOS\%s>", get_path());
        scanf("%s", input_command);
    }
}

void help(){
    printf("This is a demonstration of a file system.\n"
           "In the command line, you can enter in the \n"
           "instruction you like in terms of following \n"
           "listed researved user instructions, the command\n"
           "is similar to those in UNIX/LINUX systems.\n"
           "\n");

    printf("Help instructions: \n"
           "mkdir: mkdir dirname, create a directory\n"
           "rmdir: rmdir dirname, remove a directory\n"
           "touch: touch filename space(integer), create a file with filename and specific space\n"
           "rm: rm filename, remove a file with filename\n"
           "ls: show content in current directory\n"
           "cd: cd dirname, move to target directory\n"
           "mv: mv oldfilename newfilename, change the name of the file\n"
           "pwd: return the current path"
           "write: write filename content, write content to the file with filename, supporting \n"
           "0-9, a-z, A-Z, ws,-?\"'./,~!@#$%^&*()+_=;\n"
           "rewrite: rewrite filename content, clear previous content and write to the file again\n"
           "read: read filename numberOfCharacters, read the contend with a certain number in the file\n"
           "reread: reread filename numberOfCharacters, read from the beginning\n"
           "quit: exit the file system (dangerous, will cause reinitialization of the system)\n");
}
