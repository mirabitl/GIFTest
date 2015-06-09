#ifndef MYINTERFACE_H
#define MYINTERFACE_H
#include <string>
#include <mysql/mysql.h>

class MyInterface {
 public:
  MyInterface(std::string account);
  static void decodeAccount(std::string account,std::string &Name,std::string &Pwd,std::string &Host,std::string &Database);
  void connect();
  void disconnect();
  int32_t executeQuery(std::string stmt);
  void executeSelect(std::string stmt);
  MYSQL_ROW getNextRow();
 private:
  std::string theACcount_,theName_,thePwd_,theHost_,theDatabase_;
  MYSQL theMysql_;
  MYSQL_RES theMysqlRes_;
    };

#endif
