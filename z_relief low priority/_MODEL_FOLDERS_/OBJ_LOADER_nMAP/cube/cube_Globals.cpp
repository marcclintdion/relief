GLuint      cube_SHADER_VERTEX;                                                                                                      
GLuint      cube_SHADER_FRAGMENT;                                                                                                    
GLuint      cube_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_cube;                                                                                              
GLuint      UNIFORM_LIGHT_MATRIX_cube;                                                                                               
//--------------------------------------                                                                                                  
GLuint      UNIFORM_LIGHT_POSITION_01_cube;                                                                                          
GLuint      UNIFORM_SHININESS_cube;                                                                                                  
GLuint      UNIFORM_ATTENUATION_cube;                                                                                                  
GLuint      UNIFORM_TEXTURE_DOT3_cube;                                                                                               
GLuint      UNIFORM_TEXTURE_cube;                                                                                                    
//--------------------------------------                                                                                                  
GLfloat     cube_POSITION[]            =  {  0.0, 0.0, 0.0, 1.0};                                                                    
GLfloat     cube_ROTATE[]              =  {  0.0, 1.0,  0.0, 0.0};                                                                   
GLfloat     cube_SCALE[]               =  {  1.0, 1.0,  1.0, 1.0};                                                                   
//-----------------------------------------------------------------                                                                       
GLfloat     cube_LIGHT_POSITION_01[]   =  {  2.0, 15.0, 30.0, 1.0};                                                                  
GLfloat     cube_SHININESS             =    80.0;                                                                                    
GLfloat     cube_ATTENUATION           =     1.0;                                                                                    
//-----------------------------------------------------------------                                                                       
GLuint      cube_VBO;                                                                                                                
//-----------------------------------------------------------------                                                                       
GLuint      cube_NORMALMAP;                                                                                                          
GLuint      cube_TEXTUREMAP;                                                                                                         
