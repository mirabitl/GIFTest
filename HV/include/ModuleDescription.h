#ifndef MODULEDESCRIPTON_H
#define MODULEDESCRIPTON_H
#include <mysql/mysql.h>
#include <string>
/*

  mysql> desc modules;
  +-----------------+--------------+------+-----+---------+----------------+
  | Field      | Type     | Null | Key | Default | Extra     |
  +-----------------+--------------+------+-----+---------+----------------+
  | id       | int(10)   | NO  | PRI | NULL  | auto_increment |
  | name      | varchar(255) | NO  |   | NULL  |        |
  | address     | varchar(255) | NO  |   | NULL  |        |
  | username    | varchar(255) | NO  |   | NULL  |        |
  | password    | varchar(255) | NO  |   | NULL  |        |
  | comments    | longtext   | NO  |   | NULL  |        |
  | meteo_file   | varchar(255) | NO  |   | NULL  |        |
  | ref_pressure  | int(11)   | NO  |   | NULL  |        |
  | hvscan_pid   | int(10)   | YES |   | NULL  |        |
  | ref_temperature | double    | YES |   | 20   |        |
  | meteoLastPoint | int(11)   | YES |   | NULL  |        |
  +-----------------+--------------+------+-----+---------+----------------+
*/
class ModuleDescription {

public:
  ModuleDescription(MYSQL_ROW row)
  {
    id_=atoi(row[0]);
    name_.assign(row[1]);
    address_.assign(row[2]);
    username_.assign(row[3]);
    password_.assign(row[4]);
    comments_.assign(row[5]);
    meteo_file_.assign(row[6]);
    ref_pressure_=atoi(row[7]);
    hvscan_pid_=atoi(row[8]);
    ref_temperature_=atof(row[9]);
    meteoLastPoint_=atoi(row[10]);

  }

  inline uint32_t id(){return id_;}
  inline std::string name(){return name_;}
  inline std::string address(){return address_;}
  inline std::string username(){return username_;}
  inline std::string password(){return password_;}
  inline std::string comments(){return comments_;}
  inline std::string meteo_file(){return meteo_file_;}
  inline uint32_t ref_pressure(){return ref_pressure_;}
  inline uint32_t hvscan_pid(){return hvscan_pid_;}
  inline double ref_temperature(){return ref_temperature_;}
  inline uint32_t meteoLastPoint(){return meteoLastPoint_;}

private:

  uint32_t id_;
  std::string name_;
  std::string address_;
  std::string username_;
  std::string password_;
  std::string comments_;
  std::string meteo_file_;
  uint32_t ref_pressure_;
  uint32_t hvscan_pid_;
  double ref_temperature_;
  uint32_t meteoLastPoint_;
 
};
