#pragma once

#define PROG_MD_CLI     0
#define PROG_MD_SVR     1
#define DEF_PORT_NO     2080
#define FNAME_SZ        150
#define PROG_DEF_FNAME  "test.c"
#define PROG_DEF_SVR_ADDR   "127.0.0.1"

typedef struct prog_config{
    int     prog_mode;
    int     port_number;
    char    svr_ip_addr[16];
    char    file_name[128];
} prog_config;

#define DU_FTP_TYPE_REQUEST  1
#define DU_FTP_TYPE_DATA     2
#define DU_FTP_TYPE_ERROR    4
#define DU_FTP_TYPE_CLOSE    8

#define DU_FTP_STATUS_OK     0
#define DU_FTP_STATUS_ERR    -1
#define DU_FTP_STATUS_NOT_FOUND -2

typedef struct du_ftp_pdu {
    int version;
    int mtype;
    int msg_sz;
    int seqnum;
} du_ftp_pdu;