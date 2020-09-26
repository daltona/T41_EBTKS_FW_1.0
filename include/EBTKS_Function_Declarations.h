//
//	06/27/2020	These Function Declarations were moved from EBTKS.cpp to here.
//

//
//  1MB5/disk functions
//
void initTranslator(void);
void loopTranslator(void);
//
//  bank rom functions
//
uint8_t getRselec(void);
uint8_t *getRomSlotPtr(int slotNum);
void initRoms(void);
void setRomMap(uint8_t romId,uint8_t slotNum);

//
//  Tape functions
//
void tape_handle_command_flush(void);
void tape_handle_command_load(void);

//
//  DMA Functions
//

int32_t DMA_Read_Block(uint32_t DMA_Target_Address, uint8_t buffer[], uint32_t bytecount);
int32_t DMA_Write_Block(uint32_t DMA_Target_Address, uint8_t buffer[], uint32_t bytecount);

uint8_t  DMA_Peek8 (uint32_t address);
uint16_t DMA_Peek16(uint32_t address);

void    DMA_Poke8 (uint32_t address, uint8_t  val);
void    DMA_Poke16(uint32_t address, uint16_t val);

void    DMA_Test_1(void);
void    DMA_Test_2(void);
void    DMA_Test_3(void);
void    DMA_Test_4(void);
void    DMA_Test_5(void);

//
//  Memory Performance tests
//

void    MEM_Test_1(void);
void    MEM_Test_2(void);
void    MEM_Test_3(void);

//
//  CRT Functions
//
void initCrtEmu(void);
void dumpCrtAlpha(void);
void Write_on_CRT_Alpha(uint16_t row, uint16_t column, const char *  text);
void a3_to_a4(unsigned char *a4, unsigned char *a3);
int  base64_encode(char *output, char *input, int inputLen);
void dumpCrtAlphaAsJSON(void);
void writePixel(int x, int y, int color);
void writeLine(int x0, int y0, int x1, int y1, int color);

//
//  Bank Switched ROM support
//
bool      readBankRom(uint16_t addr);
uint8_t * getROMEntry(uint8_t romId);

//
//  HP-85 Bus interface and ISR functions
//

inline bool onReadData(uint16_t addr);
inline void onPhi_2_Rise(void);
void release_DMA_request(void);
inline void onPhi_1_Rise(void);
inline void onWriteData(uint16_t addr, uint8_t data) __attribute__((always_inline, unused));
inline void onPhi_1_Fall(void);
FASTRUN void pinChange_isr(void) __attribute__ ((interrupt ("IRQ")));
void setupPinChange(void);
void mySystick_isr(void);
void initIOfuncTable(void);
void setIOReadFunc(uint8_t addr,ioReadFuncPtr_t readFuncP);
void setIOWriteFunc(uint8_t addr,ioWriteFuncPtr_t writeFuncP);


//
//  SD Card support
//
bool loadRom(const char *fname, int slotNum, const char * description);
void saveConfiguration(const char *filename);
bool loadConfiguration(const char *filename);
void printDirectory(File dir, int numTabs);
void no_SD_card_message(void);

//
//  HP85 16k exp ram
//
void enHP85RamExp(bool en);
bool getHP85RamExp(void);

bool LineAtATime_ls_Init(char * path);
bool LineAtATime_ls_Next(void);

//
//  Log File support
//

bool open_logfile(void);
void append_to_logfile(const char * text);
void flush_logfile(void);
void close_logfile(void);
void show_logfile(void);
void clean_logfile(void);

//
//  AUXROM Support functions
//

void ioWriteAuxROM_Alert(uint8_t val);
bool onReadAuxROM_Alert(void);
void AUXROM_Poll(void);
void AUXROM_Fetch_Memory(uint8_t * dest, uint32_t src_addr, uint16_t num_bytes);
void AUXROM_Store_Memory(uint16_t dest_addr, char * source, uint16_t num_bytes);
void AUXROM_Fetch_Parameters(void * Parameter_Block_XXX , uint16_t num_bytes);
double cvt_HP85_real_to_IEEE_double(uint8_t number[]);
int32_t cvt_R12_int_to_int32(uint8_t number[]);
//void cvt_int32_to_HP85_tagged_integer(uint8_t * dest, int val);
void cvt_IEEE_double_to_HP85_number(uint8_t * dest, double val);
bool Resolve_Path(char *New_Path);
void post_custom_error_message(char * message);
void post_custom_warning_message(char * message);

//
//  AUXROM Functions/Keywords/Statements
//

void initialize_SD_functions(void);
void AUXROM_WROM(void);
void AUXROM_SDCD(void);
void AUXROM_SDCUR(void);
void AUXROM_SDCAT(void);
void AUXROM_SDMKDIR(void);
void AUXROM_SDOPEN(void);
void AUXROM_SDCLOSE(void);
void AUXROM_SDREAD(void);
void AUXROM_SDWRITE(void);
void AUXROM_SDFLUSH(void);
void AUXROM_SDSEEK(void);


//
//  Utility Functions
//

void TXD_Pulser(uint8_t count);

void EBTKS_delay_ns(int32_t count);

bool wait_for_serial_string(void);
void get_serial_string_poll(void);
void serial_string_used(void);

void Serial_Command_Poll(void);

void str_tolower(char *p);
bool MatchesPattern(char *pT, char *pP);
void HexDump_T41_mem (uint32_t start_address, uint32_t count, bool show_addr, bool final_nl);
void HexDump_HP85_mem(uint32_t start_address, uint32_t count, bool show_addr, bool final_nl);
void show_mailboxes_and_usage(void);

void Setup_Logic_Analyzer(void);
void Logic_analyzer_go(void);
void Logic_Analyzer_Poll(void);

void Simple_Graphics_Test(void);

bool is_HP85_idle(void);

#if ENABLE_THREE_SHIFT_DETECTION
bool Three_Shift_Clicks_Poll(void);
#endif

//
//  Functions that Visual Studio Code can't find, but are in the Arduino library.
//  So this is to just shut up some warning messages
//

extern size_t strlcpy(char *, const char *, size_t);    //  size parameter includes space for the null
extern size_t strlcat(char *, const char *, size_t);

