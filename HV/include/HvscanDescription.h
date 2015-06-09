#ifndef HVSCANDESCRIPTON_H
#define HVSCANDESCRIPTON_H
#include <mysql/mysql.h>
#include <string>
/*

  mysql> desc hvscan;
  +-----------------------+--------------+------+-----+---------+-------+
  | Field                 | Type         | Null | Key | Default | Extra |
  +-----------------------+--------------+------+-----+---------+-------+
  | mid                   | int(10)      | NO   | PRI | NULL    |       |
  | type                  | varchar(255) | YES  |     | NULL    |       |
  | start1                | int(10)      | NO   |     | NULL    |       |
  | step1                 | int(10)      | NO   |     | NULL    |       |
  | stop1                 | int(10)      | NO   |     | NULL    |       |
  | step2                 | int(10)      | NO   |     | NULL    |       |
  | stop2                 | int(10)      | NO   |     | NULL    |       |
  | step3                 | int(10)      | NO   |     | NULL    |       |
  | stop3                 | int(10)      | NO   |     | NULL    |       |
  | measure_time          | int(10)      | NO   |     | NULL    |       |
  | wait_time             | int(10)      | NO   |     | NULL    |       |
  | measure_time_interval | int(10)      | NO   |     | NULL    |       |
  +-----------------------+--------------+------+-----+---------+-------+
  12 rows in set (0.00 sec)



*/
class HvscanDescription {

public:
  HvscanDescription(MYSQL_ROW row)
  {
    mid_=atoi(row[0]);
    type_.assign(row[1]);
    start1_=atoi(row[2]);
    step1_=atoi(row[3]);
    stop1_=atoi(row[4]);
    step2_=atoi(row[5]);
    stop2_=atoi(row[6]);
    step3_=atoi(row[7]);
    stop3_=atoi(row[8]);
    measure_time_=atoi(row[9]);
    wait_time_=atoi(row[10]);
    measure_time_interval_=atoi(row[11]);

  }

  inline    uint32_t     mid(){return     mid_;}
  inline   std::string  type(){return type_;}
  inline   uint32_t     start1(){return     start1_;}
  inline   uint32_t     step1(){return     step1_;}
  inline   uint32_t     stop1(){return     stop1_;}
  inline   uint32_t     step2(){return     step2_;}
  inline   uint32_t     stop2(){return     stop2_;}
  inline   uint32_t     step3(){return     step3_;}
  inline   uint32_t     stop3(){return     stop3_;}
  inline   uint32_t     measure_time(){return     measure_time_;}
  inline   uint32_t     wait_time(){return     wait_time_;}
  inline   uint32_t     measure_time_interval(){return     measure_time_interval_;}



private:
  uint32_t     mid_;
  std::string type_;
  uint32_t     start1_;
  uint32_t     step1_;
  uint32_t     stop1_;
  uint32_t     step2_;
  uint32_t     stop2_;
  uint32_t     step3_;
  uint32_t     stop3_;
  uint32_t     measure_time_;
  uint32_t     wait_time_;
  uint32_t     measure_time_interval_;




 
};
