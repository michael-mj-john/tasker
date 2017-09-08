
class task {

  private:
    time_t warningTime; // epoch time for when 'warning' state kicks in
    time_t expiryTime;  // epoch time for when 'late' state kicks in
    int dueHour;
    uint32_t interval;  // seconds before it comes due again 
    enum states {
      WARNING,
      EXPIRED,
      OK         
    } state;  // there probably needs to be some kind of "recently cleared" state too.
    int LEDpin;
    

  public:
// constructor
  task ( int hour, int intervalHours, int warningMinutes, int pin ) {
    time_t currentEpoch = timeClient.getEpochTime();
    dueHour = hour;
    LEDpin = pin;
    setExpiryEpoch( currentEpoch );

    state = OK;
    
  }
  
//methods

  void updateTask( void ) {
    
    switch( state ) {
      case OK: 
         leds[0] = CHSV( HUE_GREEN, 100, 100 );
         break;
      case WARNING:
         leds[0] = CHSV( HUE_YELLOW, 100, 100 );
         break;
      case EXPIRED:
         leds[0] = CHSV( HUE_RED, 100, 100 );
         break;
    }
    
  }

  // method for lighting up LED for warning or overdue

  // method for setting next warning/expiry (don't forget to use rounding to make epochtime smoother, avoid time creep)
  void setExpiryEpoch( time_t epochTimeNow ) {
    time_t epochRoundedDown = epochTimeNow - (epochTimeNow % 3600); 
    int hour = timeClient.getHours();

    if( dueHour > hour ) {
      expiryTime = epochRoundedDown + (3600 * (dueHour - hour) );
    }
    else {
      expiryTime = epochRoundedDown + ((24 - hour) * 3600) + (dueHour * 3600);
    }
    
  }

  void setWarningEpoch( time_t epochTimeNow ) {
      
  }



  // method for querying time left??

  // method for clearing task

  
};

