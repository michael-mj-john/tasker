
class task {

  private:
    time_t warningTime; // epoch time for when 'warning' state kicks in
    time_t expiryTime;  // epoch time for when 'late' state kicks in
    uint32_t interval;  // seconds before it comes due again 
    int state;          // OK, warning, expired... there needs to be some kind of "recently cleared" state too.
    

// constructor
  task ( int dueHour, int intervalHours, int warningMinutes ) {
    time_t currentEpoch = timeClient.getEpochTime();

    // write a function that cuts epochtime down to most recent hour (hint: use modulo and subtraction)
    
    // write function to then set next expiryTime and warningTime
  }
  
//methods

  // method for lighting up LED for warning or overdue

  // method for setting next warning/expiry (don't forget to use rounding to make epochtime smoother, avoid time creep)

  // method for querying time left??

  // method for clearing task

  
};

