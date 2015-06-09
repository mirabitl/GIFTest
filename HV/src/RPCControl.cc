void RPCControl::clearDetectors()
{
  for (std::vector<DetectorDescription*>::iterator itd=theDetectors_.begin();itd!=theDetectors_.end();itd++)
    delete (*itd);
  theDtectors_.clear();
}
void RPCControl::doMonitoring(uint32_t mid)
{
  theStatus_.set(RPCControl::MONITORING_RUNNING,1);

  // Query detectors
  std::stringstream stmt;
  stmt<<"SELECT * FROM detectors WHERE id="<<mid;
  theMyInterface_->executeSelect(stmt.str());
  MYSQL_ROW row=NULL;
  this->clearDetectors();
  while (row=theMyInterface_->getNextRow()!=NULL)
    {
      DetectorDescription* d =new DetectorDescription(row);
      theDetectors.push_back(d);
    }
  theMyInterface_->disconnect();

  // Loop on detectors and store HV info into HVMON
  while (theMonitoringIsStarted_)
    {
      theSem_.lock();
      theMyInterface_->connect();
      theHVInterface->Connect();
      for (std::vector<DetectorDescription*>::iterator itd=theDetectors_.begin();itd!=theDetectors_.end();itd++)
	{
	  int32_t status=theHVInterface_->GetStatus((*itd)->slot()*6+id_(*itd)->channel());
	  float v0=theHVInterface_->GetVoltageSet((*itd)->slot()*6+id_(*itd)->channel());
	  float vmon=theHVInterface_->GetVoltageRead((*itd)->slot()*6+id_(*itd)->channel());
	  float i0=theHVInterface_->GetCurrentSet((*itd)->slot()*6+id_(*itd)->channel());
	  float imon=theHVInterface_->GetCurrentRead((*itd)->slot()*6+id_(*itd)->channel());
	  stmt.str(std::string());
	  stmt<<"INSERT INTO HVMON(MID,DETID,STATUS,V0,I0,VMON,IMON) VALUES("<<
	    mid<<","<<
	    (*itd)->id()<<","<<
	    status<<","<<
	    v0<<","<<
	    i0<<","<<
	    vmon<<","<<
	    imon<<")";
	  theMyInterface_->executeQuery(stmt.str());
	}
      theHVInterface->Disconnect();

      theMyInterface_->disconnect();
      theSem_.unlock();

      ::sleep(theMonitoringPeriod_);
    }
  theStatus_.set(RPCControl::MONITORING_RUNNING,0);
}
void RPCControl::StartMonitoring(uint32_t mid)
{
  //  boost::thread_group gMonitoring_;
  theMonitoringIsStarted_=true;
  gMonitoring_.create_thread(boost::bind(&RPCControl::doMonitoring, this,mid));
  
  g.join_all();
}	
void RPCControl::StopMonitoring()
{
  theMonitoringIsStarted_=false;
  gMonitoring_.join_all();
}

void RPCControl::doHVScan(uint32_t mid)
{
  theStatus_.set(RPCControl::HVSCAN_RUNNING,1);
  theSem_.lock();
  theMyInterface_->connect();
      // Query detectors
  std::stringstream stmt;
  stmt<<"SELECT * FROM hvscan WHERE id="<<mid<<" LIMIT=1";
  theMyInterface_->executeSelect(stmt.str());
  MYSQL_ROW row=NULL;
  theHVInterface->Connect();
  int     hour, noDet = 0, error = 0, type;
 int     start1, step1, stop1, start2, start3, step2, stop2, step3, stop3, wtime, mtime, intval;
  while (row=theMyInterface_->getNextRow()!=NULL)
    {
          
      type = atoi(row[1]); 
      start1 = atoi(row[2]); 
      step1 = atoi(row[3]); 
      stop1 = atoi(row[4]); 
      step2 = atoi(row[5]); 
      stop2 = atoi(row[6]); 
      step3 = atoi(row[7]); 
      stop3 = atoi(row[8]); 
      mtime = atoi(row[9]);
      wtime = atoi(row[10]);
      intval = atoi(row[11]);
      
    }
}
