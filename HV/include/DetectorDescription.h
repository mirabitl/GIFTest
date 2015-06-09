#ifndef DETECTORDESCRIPTON_H
#define DETECTORDESCRIPTON_H
#include <mysql/mysql.h>
#include <string>
/*
  mysql> desc detectors;
+----------+--------------+------+-----+---------+----------------+
| Field    | Type         | Null | Key | Default | Extra          |
+----------+--------------+------+-----+---------+----------------+
| id       | int(10)      | NO   | PRI | NULL    | auto_increment |
| mid      | int(10)      | NO   |     | NULL    |                |
| name     | varchar(255) | NO   |     | NULL    |                |
| channel  | int(10)      | NO   |     | NULL    |                |
| slot     | int(10)      | NO   |     | NULL    |                |
| comments | longtext     | NO   |     | NULL    |                |
| process  | int(10)      | NO   |     | 0       |                |
+----------+--------------+------+-----+---------+----------------+

 */
class DetectorDescription {

 public:
  DetectorDescription(MYSQL_ROW row)
    {
     id_=atoi(row[0]);
     mid_=atoi(row[1]);
     name_.assign(row[2]);
     channel_=atoi(row[3]);
     slot_=atoi(row[4]);
     comments_.assign(row[5]);
     process_=atoi(row[6]);
    }
  inline uint32_t id(){return id_;}
  inline uint32_t mid(){return mid_;}
  inline uint32_t channel(){return channel_;}
  inline uint32_t slot(){return slot_;}
  inline uint32_t process(){return process_;}
  inline std::string name(){return name_;}
  inline std::string comments(){return comments_;}
 private:
  uint32_t id_,mid_,slot_,channel_,process_;
  std::string name_,comments_;
  
};
