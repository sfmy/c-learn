#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void showHelpMsg () {
	printf("帮助信息：\n");
	printf("--pass 加密密码\n");
	printf("--file 加密文件\n");
	printf("--type f文件\tv视频\t默认为文件类型\n");
}

/*
 * 仅仅显示帮助信息
 * @param argc 命令个数
 * @param argv 命令信息
 */
int justShowHelp (int argc, char* argv[]) {
	int i = 0;
	while (++i < argc) {
		if ((argv[i][0] == '-' && argv[i][1] == 'h') || (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] == 'h')) {
			showHelpMsg();
			return 1;
		}
	}
	return 0;
}

/*
 * 加密文本类文件
 * @param file_name 文件名
 * @param pass 密码
 */
void encodeFile (char * file_name, char * pass) {
	int file = open(file_name, O_RDWR);
	if (file == -1) {
		printf("打开文件%s失败！\n", file_name);
		return;
	}
	char buff[16];
	int i;
	int len = read(file, buff, sizeof(buff));
	while(len) {
		for (i = 0; i < len; ++i) {
			buff[i] ^= pass[i%sizeof(pass)];
		}
		lseek(file, -len, SEEK_CUR);
		write(file, buff, len);
		len = read(file, buff, sizeof(buff));
	}
	close(file);
	printf("加密文件%s成功！\n", file_name);
}

/*
 * 加密视频类文件
 * @param file_name 文件名
 * @param pass 密码
 */
void encodeVideo (char * file_name, char * pass) {
	int file = open(file_name, O_RDWR);
	if (file == -1) {
		printf("打开文件%s失败！\n", file_name);
		return;
	}
	char buff[1024];
	int i;
	int len = read(file, buff, sizeof(buff));
	while(len) {
		for (i = 0; i < len; ++i) {
			buff[i] ^= pass[i%sizeof(pass)];
		}
		lseek(file, -len, SEEK_CUR);
		write(file, buff, len);
		break;
	}
	close(file);
	printf("加密文件%s成功！\n", file_name);
}

int main(int argc, char **argv) {
	if (justShowHelp(argc, argv))
		return 0;
	char * file;
	char * pass;
	char * type = "f";
	int i = 0;
	int decode = 0;

	while (++i < argc) {
		if (strcmp(argv[i], "--decode") == 0) {
			decode = 1;
		}
		if (strcmp(argv[i], "--pass") == 0) {
			if (i+1 < argc)
				pass = argv[++i];
		}
		if (strcmp(argv[i], "--file") == 0) {
			if (i+1 < argc)
				file = argv[++i];
		}
		if (strcmp(argv[i], "--type") == 0) {
			if (i+1 < argc && argv[++i][0] == 'v')
				type = "v";
		}
	}
	if (!pass || !file) {
		showHelpMsg();
		return 0;
	}
	if (strcmp(type, "f") == 0) {
		encodeFile(file, pass);
	}
	else if (strcmp(type, "v") == 0) {
		encodeVideo(file, pass);
	}

	return 0;
}
