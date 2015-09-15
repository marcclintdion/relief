#define var GLfloat
//####################################################################################################################
                                

#ifdef WIN32
        #define   glGenerateMipmap       glGenerateMipmapEXT        
        #define   glGenFramebuffers      glGenFramebuffersEXT    
        #define   glBindFramebuffer      glBindFramebufferEXT          
        #define   glFramebufferTexture2D glFramebufferTexture2DEXT            
         
        #define   STRICT
        #define   WIN32_LEAN_AND_MEAN
        #include <windows.h>
        #include <iostream.h>
        #include <fstream.h>
        //using namespace std; //___used for string object

       //-----------------------------------------------------------------------------


        #include <GL/gl.h>
        #include <GL/glu.h>        
        #include "headerFiles/glext.h" 
        #include "headerFiles/glext_Init_A.cpp" 

      
        void InitGL(void);   
        void RenderGL(void); 
        
 
        void ProcessKeyboard(void);
                
        int  screenWidth;
        int  screenHeight; 
        var  viewWidth;
        var  viewHeight;          
        
        //----------------------------------------------------------------------
        //var         eyePosition[]                  =  {0, 0.1, 5.4, 1.0};
      
      
        var         fieldOfView                       =  35;


        var         moveSet[]                         =  {0, -0.630001, -4.74999, 0.0};
        var         rotateModelWithLeftMouse[]        =  {1.79982, -16.8, 0.0, 0.0};



       
        var         look_UP_DOWN;
        var         look_LEFT_RIGHT;
        //----------------------------------------------------------------------

        //-------------------------------
        var keys[256], keypressed[256];        
        #include "cpp/WGL_ARB_multisample.h"
        //-------------------------------





        
        #include "headerFiles/VSync.h"   
        
        #include <windows.h>

        void      ConfigureAndLoadTexture(GLubyte *textureData, GLint texWidth, GLint texHeight );
        #include "headerFiles/glaux.h"        
        #include "headerFiles/FreeImage.h"
        #include "cpp/freeImage.cpp"
        //------------------------------------------
 
    
#endif

//####################################################################################################################


#include <math.h>
  

//####################################################################################################################

#include "MATRIX_MATH.cpp"

//####################################################################################################################



//-------------------------------------------------------------------------------------------------------------------- 

int TEXTURE_WIDTH  = 1024;
int TEXTURE_HEIGHT = 1024;
//------------------------------------
GLuint      depth;
GLuint      fboId_2D; 
GLuint      shadowMap_2D;
//GLuint    shadowMap_3D;

//--------------------------------------------------------------------------------------------------------------
#define BUFFER_OFFSET(i) ((char *)0 + (i))
//----------------------------------------------------------------------------------------

        extern GLuint msaaFramebuffer;

        void RenderGL(void);
        void InitGL  (void);
        void shutDownGL(void);
      
    
       
      

                
       
        #ifdef __APPLE__
               var viewWidth;
               var viewHeight;
               GLuint  viewFramebuffer;        
        #endif 
          
        //-------------------------------------------------------------------------------

 


//#########################################################################################################|_FREE_IMAGE

void ConfigureAndLoadTexture(GLubyte *textureData, GLint texWidth, GLint texHeight )
{

        #ifdef __APPLE__
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); 
        //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);	        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData);
        glGenerateMipmap(GL_TEXTURE_2D);
        #endif
        
        #ifdef WIN32
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST); 
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);	        
        glTexParameteri( GL_TEXTURE_2D, GL_GENERATE_MIPMAP_SGIS, GL_TRUE );
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, textureData);
        #endif 
}

//===============================================================================================================================                                                   

var     modelView[16];
var     projection[16];
var     mvpMatrix[16];
var     mvpMatrixInverse[16];
var     lightMatrix[16];  
var     moveSetMatrix[16]; 
var     textureMatrix[16];
var     ProjectionShadow[16];
var     LightModelViewMatrix[16];


GLuint      UNIFORM_MODELVIEWPROJ;
GLuint      UNIFORM_MODELVIEWPROJ_INVERSE;
GLuint      UNIFORM_LIGHT_MATRIX;

//===============================================================================================================================
                               

//######################################################################################################################
                                
                                
                                var groupSelection       =    1.0;                           
                                
                                var select_POSITION[]    = {  0.0, 0.0, 0.0, 0.0};
                                
                                var spinModel            =    0.0;
                                //---------------------------------------------------- 
                                 
                                
                               //====================================================================================                                          
                              
                               var         facing_UP_LIGHT_POSITION_01[]              =  {0, 22, -5.40002, 1.0};
                               //var         facing_UP_LIGHT_POSITION_01[]             =  {0, 4.9, 12.6, 1.0};//from above
                               
                               //-------------------------------------------------------------------------------------------;
                               var         facing_UP_quadraticAttenuation            =  00.0;
                               var         facing_UP_linearAttenuation               =  0;
                               var         facing_UP_constantAttenuation             =  0.0;                     
                               
                               var         zDirectionBias                            =  274.219;
                               var         facing_UP_SHININESS                       =  0;   
                               //----------
                               #include "_MODEL_FOLDERS_/facing_UP/facing_UP_Globals.cpp"                                                                
                               //====================================================================================                                          
                               var         facing_VIEW_LIGHT_POSITION_01[]             =  {10.3, 18.1, 100.599, 1.0};
  
                               //-------------------------------------------------------------------------------------------;
                               var         facing_VIEW_quadraticAttenuation            =  00.0;
                               var         facing_VIEW_linearAttenuation               =  0;
                               var         facing_VIEW_constantAttenuation             =  0.0;                     
                               
                               var         facing_VIEW_SHININESS              =  0;   
                               //----------                               
                               #include "_MODEL_FOLDERS_/facing_VIEW/facing_VIEW_Globals.cpp"                                                                
                               //====================================================================================                                          


//======================================================================================================================================================================================


          
          
//###################################################################################################################################################
//###################################################################################################################################################
//###################################################################################################################################################

var shaderNumber = 0;

void SelectShader(var shaderNumber)
{    
     //--------------------------------------------------------------------------------------
     if(shaderNumber == 1)
     {
            //#include "_SHADERS/fresnel/DelylaShield/DelylaShield_RENDER.cpp"        
     }
     //--------------------------------------------------------------------------------------
  
}

//###################################################################################################################################################
//###################################################################################################################################################
//###################################################################################################################################################

void InitGL( void )//__END_INIT__@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@___BEGIN_INIT__
{
       
       
       

   
        //==========================================================================
        #ifdef WIN32 
            #include "cpp/setPixelFormat.cpp"
            #include "headerFiles/glext_Init_B.cpp" 
            //-------------------------------------
            SetVSyncState(true);        
        #endif
        
//==========================================================================================================================================================================



        
        //====================================================================================================================    
        glGenTextures(1, &shadowMap_2D);
        glBindTexture(GL_TEXTURE_2D, shadowMap_2D);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0, GL_BGRA, GL_UNSIGNED_BYTE, 0);
        glBindTexture(GL_TEXTURE_2D, 0);   
        //--------------------------------------------------------------------------------------------------------------------
        glGenFramebuffers(1, &fboId_2D);
        glBindFramebuffer(GL_FRAMEBUFFER, fboId_2D);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, shadowMap_2D, 0);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        //######################################################################################################________SHADERS  
        //######################################################################################################________SHADERS                                        
       
        //================================================================       
  
        //====================================================================================   
        #include "_MODEL_FOLDERS_/facing_UP/facing_UP_Init.cpp"                                                                   
        //====================================================================================                                          
        #include "_MODEL_FOLDERS_/facing_VIEW/facing_VIEW_Init.cpp"                                                                   
        //====================================================================================                                          
    
                                
          
//=================================================================================================================== 



    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);	
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glAlphaFunc(GL_GREATER, 0.1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);  


//=====================================================================================================================

    



}//__END_INIT__@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@___END_INIT__



//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################

GLfloat rotateModel;

void RenderGL(void)
{
        



//*******************************************************************************************************************************************************
//*******************************************************************************************************************************************************
//*******************************************************************************************************************************************************
//*******************************************************************************************************************************************************       
        
        //========================================================================================================================================================        
        //---------------------------------------------------RETURN_TO_MAIN_FRAMEBUFFER____________________!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        //---------------------------------------------------RETURN_TO_MAIN_FRAMEBUFFER____________________!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        //========================================================================================================================================================        
        #ifdef __APPLE__    
            glBindFramebuffer(GL_FRAMEBUFFER, msaaFramebuffer);
        #endif    
        //========================================================================================================================================================        
        //---------------------------------------------------RETURN_TO_MAIN_FRAMEBUFFER____________________!!!!!!!!!!!!!!!!!!!!!!!!!!!!        
        //---------------------------------------------------RETURN_TO_MAIN_FRAMEBUFFER____________________!!!!!!!!!!!!!!!!!!!!!!!!!!!!          
        //========================================================================================================================================================



        //=========================================================================================================================================================    
        glClearColor( 0.0f, 0.0f, 0.0f, 1.0 );
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); 
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
        //----------------------------------------------------------------------------------
        glViewport(0, 0, (GLsizei)viewWidth, (GLsizei)viewHeight);
        PerspectiveMatrix(projection, fieldOfView, viewWidth / viewHeight, 0.1, 1000);
        //=========================================================================================================================================================
        #ifdef __APPLE__
        Rotate(projection, 0.0, 0.0, 1.0, -90.0);//_____FOR_iOS_LANDSCAPE_VIEW 
        #endif        
        //=========================================================================================================================================================        
        //projection[12] = eyePosition[1];
        //projection[13] = eyePosition[0];
        //projection[15] = eyePosition[2];
        //Rotate(projection, 1.0, 0.0, 0.0,  look_UP_DOWN);
        //Rotate(projection, 0.0, 1.0, 0.0, -look_LEFT_RIGHT);  


rotateModel += 0.1;

//glEnable(GL_BLEND);
//====================================================================================   
#include "_MODEL_FOLDERS_/facing_UP/facing_UP_Render.cpp"                                                                 
//====================================================================================                                          
#include "_MODEL_FOLDERS_/facing_VIEW/facing_VIEW_Render.cpp"                                                                 
//====================================================================================                                          
//glDisable(GL_BLEND);  




}//_END_RenderGL()


//#######################################################################################################################################################
//#######################################################################################################################################################
//#######################################################################################################################################################
//#######################################################################################################################################################


void ProcessKeyboard(void)
{

     //====================================================================================                                          
 
    //=======================================================================================                                           
	                                                                                                                                  
    if (keys['L'])                                                                                                                      
    {	                                                                                                                                  
             facing_VIEW_LIGHT_POSITION_01[0]         +=   .1;                                                                            
    }                                                                                                                                   
    if (keys['J'])                                                                                                                   
    {                                                                                                                                   
             facing_VIEW_LIGHT_POSITION_01[0]         -=   .1;                                                                         
    }    
    if (keys['I'])                                                                                                                      
    {	                                                                                                                                  
             facing_VIEW_LIGHT_POSITION_01[1]         +=   .1;                                                                            
    }	                                                                                                                                  
    if (keys['K'])                                                                                                                      
    {	                                                                                                                                  
             facing_VIEW_LIGHT_POSITION_01[1]         -=   .1;                                                                            
    }                                                                                                                                   
    if (keys['O'])                                                                                                                      
    {	                                                                                                                                  
             facing_VIEW_LIGHT_POSITION_01[2]         +=   .1;                                                                            
    }	                                                                                                                                  
    if (keys['U'])                                                                                                                      
    {	                                                                                                                                  
             facing_VIEW_LIGHT_POSITION_01[2]         -=   .1;      
    }
    //=======================================================================================        
    if (keys['M'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])                                                                                                                      
    {	                                                                                                                                  
             facing_UP_constantAttenuation                  +=  0.001;                                                                            
    }	                                                                                                                                  
    if (keys['N'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])                                                                                                                      
    {	                                                                                                                                  
             facing_UP_constantAttenuation                  -=  0.001;                                                                            
    }  
    //----------------------------------------------------------------
    if (keys['M'] && keys[VK_SHIFT] && !keys[VK_CONTROL])                                                                                                                      
    {	                                                                                                                                  
             facing_UP_linearAttenuation                     +=  0.01;                                                                            
    }	                                                                                                                                  
    if (keys['N'] && keys[VK_SHIFT] && !keys[VK_CONTROL])                                                                                                                      
    {	                                                                                                                                  
             facing_UP_linearAttenuation                     -=  0.01;                                                                            
    }  
    //----------------------------------------------------------------    
    if (keys['M'] && !keys[VK_SHIFT] && keys[VK_CONTROL])                                                                                                                      
    {	                                                                                                                                  
              facing_UP_quadraticAttenuation                 +=  0.1;                                                                            
    }	                                                                                                                                  
    if (keys['N'] && !keys[VK_SHIFT] && keys[VK_CONTROL])                                                                                                                      
    {	                                                                                                                                  
             facing_UP_quadraticAttenuation                  -=  0.1;                                                                            
    }  
    //----------------------------------------------------------------


    

    
   
    if (keys['X'])                                                                                                                      
    {	                                                                                                                                  
             fieldOfView                    +=  0.1;                                                                            
    }	                                                                                                                                  
    if (keys['Z'])                                                                                                                      
    {	                                                                                                                                  
             fieldOfView                    -=  0.1;                                                                            
    }  
    if (keys['V'])                                                                                                                      
    {	                                                                                                                                  
             zDirectionBias                         +=  1.01;                                                                            
    }	                                                                                                                                  
    if (keys['C'])
    {	                                                                                                                                  
             zDirectionBias                         -=  1.1;                                                                            
    }      
          
   //==============================================================================
/*    if (keys['C'] && KEY_C_IS_RESET && !keys[VK_SHIFT])                                                                                                                      
    {	                                                                                                                                  
            stepVBOcount                    -=  10; 
            KEY_C_IS_RESET                    = false;                                                                           
    }	                                                                                                                                  
    if (!keys['C'])                                                                                                                      
    {	                                                                                                                                  
            KEY_C_IS_RESET                    = true;                                                                           
    } 
    //-----------------------------------------------------------------------------   
    if (keys['V'] && KEY_V_IS_RESET && !keys[VK_SHIFT])                                                                                                                      
    {	                                                                                                                                  
            stepVBOcount                    +=  10;
            KEY_V_IS_RESET                    = false;                                                                            
    }             
    if (!keys['V'])                                                                                                                      
    {	                                                                                                                                  
            KEY_V_IS_RESET                    = true;                                                                           
    } 
*/    //-----------------------------------------------------------------------------    
   //==============================================================================
       //----------------------------------------------
    if(keys[VK_F8])
    {
         ofstream outSettings("settings.cpp");
             
         //--------------------------------------------------------------------------------------------------------------------------------
         outSettings << "var         facing_VIEW_LIGHT_POSITION_01[]             =  {"   << facing_VIEW_LIGHT_POSITION_01[0] << ", "
                                                                                       << facing_VIEW_LIGHT_POSITION_01[1] << ", "
                                                                                       << facing_VIEW_LIGHT_POSITION_01[2] << ", 1.0};\n\n";            
         outSettings << "            //-------------------------------------------------------------------------------------------" << ";\n";              
         
         outSettings << "                               var         facing_UP_quadraticAttenuation            =  "    << facing_UP_quadraticAttenuation << ";\n";
         outSettings << "                               var         facing_UP_linearAttenuation               =  "    << facing_UP_linearAttenuation << ";\n";            
         outSettings << "                               var         facing_UP_constantAttenuation             =  "    << facing_UP_constantAttenuation << ";\n";                        
         outSettings << "            //-------------------------------------------------------------------------------------------" << ";\n";
         outSettings << "var         facing_UP_SHININESS                       =  "    << facing_UP_SHININESS << ";\n\n\n";             
         outSettings << "var         zDirectionBias                            =  "    << zDirectionBias << ";\n";             
         outSettings << "            //-------------------------------------------------------------------------------------------" << "\n";    
         //---------------------------------------------------------------------------------------------------------------------------------  
         outSettings << "        var         fieldOfView                       =  "    << fieldOfView << ";\n\n\n";                      
         
         outSettings << "        var         moveSet[]                         =  {"   << moveSet[0]    << ", "
                                                                                       << moveSet[1]    << ", "
                                                                                       << moveSet[2]    << ", "         
                                                                                       << "0.0};\n";  
         
         outSettings << "        var         rotateModelWithLeftMouse[]        =  {"   << rotateModelWithLeftMouse[0] << ", "
                                                                                       << rotateModelWithLeftMouse[1] << ", "
                                                                                       << "0.0, 0.0};\n\n";   
         //--------------------------------------------------------------------------------------------------------------------------------             //------------------------------------------------------------------------------------------------------------------------------
         //outSettings << "      var         eyePosition[]                     =  {"   << eyePosition[0] << ", "
                                                                                    // << eyePosition[1] << ", "
                                                                                     //<< eyePosition[2] << ", 1.0};\n\n";            
            
             //--------------------------------------------------------------------------------------------------------------------------              
        
       }
       //----------------------------------------------      
     
    //=======================================================================================                                           
    if (keys[VK_TAB] && TAB_KEY_RESET && !keys[VK_SHIFT])                                                                                                                   
    {                                                                                                                                   
             groupSelection         +=  1;                                                                         
             TAB_KEY_RESET           = false;
    }   
    if (!keys[VK_TAB])                                                                                                                   
    {                                                                                                                                   
            TAB_KEY_RESET           = true;
    }    
    
    if (keys[VK_TAB] && TAB_KEY_RESET && keys[VK_SHIFT])                                                                                                                   
    {                                                                                                                                   
             groupSelection         -=  1;                                                                         
             TAB_KEY_RESET           = false;
    }   
    if (!keys[VK_TAB])                                                                                                                   
    {                                                                                                                                   
            TAB_KEY_RESET           = true;
    }     
    
    
    
    //=======================================================================================     
    if (keys['A'])                                                                                                                   
    {                                                                                                                                   
             moveSet[0]         -=  0.03;                                                                         
    }	                                                                                                                                  
    if (keys['D'])                                                                                                                      
    {	                                                                                                                                  
             moveSet[0]         +=  0.03;                                                                            
    }                                                                                                                                   
    if (keys['W'])                                                                                                                      
    {	                                                                                                                                  
             moveSet[1]         +=  0.03;                                                                            
    }	                                                                                                                                  
    if (keys['S'])                                                                                                                      
    {	                                                                                                                                  
             moveSet[1]         -=  0.03;                                                                            
    }                                                                                                                                   
    if (keys['E'])                                                                                                                      
    {	                                                                                                                                  
             moveSet[2]         +=  0.03;                                                                            
    }	                                                                                                                                  
    if (keys['Q'])                                                                                                                      
    {	                                                                                                                                  
             moveSet[2]         -=  0.03;      
    }
    //=======================================================================================        
     
}//_END_ProcessKeyboard()



//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################



void shutDownGL( void )
{
        
        //====================================================================================  
        #include "_MODEL_FOLDERS_/facing_UP/facing_UP_Shutdown.cpp"                                                               
        //====================================================================================                                          
        

     
}


//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================




