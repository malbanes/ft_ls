OPENDIR,READDIR,CLOSEDIR

int	main(int ac, char *av)
{
	dirent *dp;
	DIR	*dirp;
	t_lst	*list;

	if (ac == 1)
	{
		if (dirp = opendir(".") == NULL)
			return (ERROR);
		while ((dp = readdir(dirp)) != NULL)
		{
			list = add_av(dp);
		}
	closedir(dirp);
	return (0);
}

# ifndef _DARWIN_FEATURE_64_BIT_INODE

	d_ino
	d_reclen
	d_type
	d_namelen
	d_name[256]

# endif

#ifdef ..
	d_name[1024]
#endif

filetype

DT_UNKNOWN
    The type is unknown. On some systems this is the only value returned.

DT_REG
    A regular file.

DT_DIR
  A directory.

DT_FIFO
    A named pipe, or FIFO. See section 15.3 FIFO Special Files.

DT_SOCK
    A local-domain socket.

DT_CHR
	A character device.

	DT_BLK
    A block device. 
////////////////

	STAT et LSTAT

int	stat(char *path, stat * buff)

	lstat retourne les info du lien sur des fichier linke tandis aue stat retourne les info du fichier linke
	on utiliserq donc lstat

	struct stat: y'a aussi une histoire avec la marcro

utilise pour ls -l
