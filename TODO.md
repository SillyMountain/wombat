# WOMBAT - ToDos


> This file list all of the Stuff that is planned for the womabt library right now. This is not a final nor complete list.

### Collections

 Required Collection Types:
 * [ ] List
 * [ ] Set
 * [ ] LazyArray (do not directly free memory)
 * [ ] StaticArray (fixed size)
 * [ ] ObservableCollection (with callbacks on XY)
 * [ ] Map
 
### Logging Library

The logger must be able to do the following thigs:

 * [ ] Class based logging (each class uses its own logger -> easier to find it in logs)
 * [ ] Multiplexing to different Appenders
   * [ ] Terminal
   * [ ] File
   * [ ] FileRotation
   * [ ] Syslog
   * [ ] SQL Database
   * [ ] Socket
 * [ ] Exception logging
 * [ ] Log levels
   * [ ] FATAL (does also crash application)
   * [ ] ERROR
   * [ ] WARNING
   * [ ] INFO
   * [ ] DEBUG
   * [ ] TRACE
