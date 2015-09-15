     #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      cube_relief_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_cube_relief =                                                                                                        

      "    #define highp                                                                                        \n"                           

      "    uniform highp   vec4   light_POSITION_01;                                                            \n"                           
      "    uniform         mat4   mvpMatrix;                                                                    \n"                           
      "    uniform         mat4   mvMatrix;                                                                     \n"        
      "    uniform         mat4   lightMatrix;                                                                  \n"                           
     
      "    uniform         vec4   linearTransform;                                                              \n"  
      "    attribute       vec4   position;                                                                     \n"                           
      "    attribute       vec3   normal;                                                                       \n"         
      "    attribute       vec3   tangent;                                                                      \n"             
      "    attribute       vec2   texture;                                                                      \n"                           

      "    varying highp   vec4   lightPosition_PASS;                                                           \n"                           
      "    varying highp   vec3   lightDirection;                                                               \n"        
      "    varying highp   vec3   EyeDir;                                                                       \n"  
      "    uniform highp  float   shininess;                                                                                                        \n"                       
      "    uniform highp  float   attenuation;                                                                                                      \n"                       
           
      "    varying highp   vec3   column0;                                                                      \n"   
      "    varying highp   vec3   column1;                                                                      \n"   
      "    varying highp   vec3   column2;                                                                      \n"        
      
      "    varying highp   vec2   varTexcoord;                                                                  \n"                           

      "    vec3 view;                                                                                           \n"    

      "    void main()                                                                                          \n"                           
      "    {                                                                                                    \n"                           
      "        column0               =  vec3(mvpMatrix[0].xyz);                                                 \n"   
      "        column1               =  vec3(mvpMatrix[1].xyz);                                                 \n"   
      "        column2               =  vec3(mvpMatrix[2].xyz);                                                 \n"        
      
      "        vec3 n                = (mvMatrix * vec4(normal, 0.0)).xyz;                                          \n"
      "        vec3 t                = (mvMatrix * vec4(tangent, 0.0)).xyz;                                         \n"
      "        vec3 b                =  normalize( cross(n, t));                                                \n"  
      
      "        vec3 vertexPosition   =  vec3(mvMatrix * position);                                              \n"        
      "        vec3 dirEye           =  vec3(0.0, 0.0, 100.0);                          \n" 

   
     
      "        EyeDir.x              =  dot(t.xyz, dirEye);                                                    \n"  
      "        EyeDir.y              =  dot(b.xyz, dirEye);                                                    \n"  
      "        EyeDir.z              =  dot(n.xyz, dirEye);                                                    \n"  
     
      //"        EyeDir                = -(mvMatrix * vec4(EyeDir, 0.0));                                                     \n"       
     //-----------------------------------------------------------------------------------------------------------------
      "        lightPosition_PASS    =  normalize(lightMatrix * light_POSITION_01);                             \n"                           

      "        varTexcoord           =  texture;                                                                \n"                           

      "        gl_Position           =  mvpMatrix * position;                                                   \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      cube_relief_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(cube_relief_SHADER_VERTEX, 1, &vertexSource_cube_relief, NULL);                                                                        
      glCompileShader(cube_relief_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_cube_relief =                                                                                                            

      " #ifdef GL_ES                                                                                                                               \n"                       
      " #else                                                                                                                                      \n"                       
      " #define highp                                                                                                                              \n"                       
      " #endif                                                                                                                                     \n"                       

      "    uniform sampler2D     Texture1;                                                                                                         \n"                       
      "    uniform sampler2D     NormalMap;                                                                                                        \n"                       
      "    uniform sampler2D     HeightMap;                                                                                                        \n"        
      "    uniform highp float   shininess;                                                                                                        \n"                       
      "    uniform highp float   attenuation;                                                                                                      \n"                       
      "    uniform highp vec4    light_POSITION_01;                                                                                                \n"    
      "    varying highp vec4    lightPosition_PASS;                                                                                               \n"                       
      "    varying highp vec3    lightDirection;                                                                                                   \n"      
      "    varying highp vec3    EyeDir;                                                                                                           \n"  
      "    varying highp vec3    column0;                                                                                                          \n"   
      "    varying highp vec3    column1;                                                                                                          \n"   
      "    varying highp vec3    column2;                                                                                                          \n"  
            
      "    varying highp vec2    varTexcoord;                                                                                                      \n"                       

      "            highp float   NdotL1;                                                                                                           \n"                       
      "            highp vec3    normal;                                                                                                           \n"                       
      "            highp vec3    NormalTex;                                                                                                        \n"                       


      " vec2 RayCast(sampler2D HMap, vec2 tc, vec3 ray);                                                                         \n"  


      "     void main()                                                                                                          \n"                       
      "     {                                                                                                                    \n"                       
 
      "         vec2 TexCoords = RayCast(HeightMap, varTexcoord.xy, EyeDir);                                                     \n"      
      //------------------------------------------------------------------------------------------------------------------------
      "         mat3 n = mat3(column0, column1, column2);                                                                        \n"       
      
      "         NormalTex                  =  texture2D(NormalMap,  TexCoords.xy).xyz;                                           \n"                       
      "         NormalTex                  = (NormalTex - 0.5);                                                                  \n"                       
      "         normal                     =  normalize(n * NormalTex.xyz);                                                          \n"                       
      "         NdotL1                     =  dot(normal, normalize(light_POSITION_01.xyz));                                     \n"   
      //------------------------------------------------------------------------------------------------------------------------      
      
      "         gl_FragColor          =  vec4(1.0, 1.0, 1.0, 1.0) * NdotL1  * .2                                                 \n"                       

      "                               +  texture2D(Texture1, TexCoords.xy) *NdotL1 * 1.0                                         \n"                       

      "                               +  texture2D(Texture1, TexCoords.xy) * pow(NdotL1, 50.0) * vec4(2.0, 1.0, .1, 1.0)*0.0;    \n"                       

      "    }                                                                                                                     \n"   
      
"   vec2 RayCast(sampler2D HMap, vec2 tc, vec3 ray)                                                                              \n"  
"   {                                                                                                                            \n"  
"       int numsteps = 10;                                                                                                       \n"  
"       int substeps = 5;                                                                                               \n"  

"       float height = 1.0;                                                                                             \n"  
"       float step= 1.0/float(numsteps);                                                                                \n"  
"       int currStep;                                                                                                   \n"  
"       vec4 tHeight= texture2D(HMap,tc);                                                                               \n"  
"       vec2 delta = vec2(-ray.x,-ray.y) * 0.0015 / (ray.z);                                                              \n"  

    "       for(int i=1; i<=numsteps;i++)                                                                               \n"  
"       {                                                                                                               \n"  
"           if(tHeight.x <= height)                                                                                     \n"   
"           {                                                                                                           \n"  
"               height -=step;                                                                                          \n"  
            //height = 1.0 - step*(i);                                                                                  \n"  
"               currStep=i;                                                                                             \n"  
"               tHeight= texture2D(HMap,tc-delta*height);                                                               \n"  
"           }                                                                                                           \n"  
"       }                                                                                                               \n"  

"       currStep-=1;                                                                                                    \n"  
"       height +=step;                                                                                                  \n"  

"       for(int i=0; i<substeps;i++)                                                                                    \n"  
"       {                                                                                                               \n"  
"           step*=0.5;                                                                                                  \n"  
"           height -=step;                                                                                              \n"  
"           tHeight= texture2D(HMap,tc-delta*height);                                                                   \n"  
    
"           if(tHeight.x >= height)                                                                                     \n"
"           {                                                                                                           \n"
"               height+=step;                                                                                           \n"      
"           }                                                                                                           \n"
"       }                                                                                                               \n"

"      return tc-delta*height*ray.xy;                                                                                          \n"

"    }\n";
      
      
      
                                                                                                                                    

    
/*   
      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      cube_relief_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_cube_relief =                                                                                                        

      "    #define highp                                                                                       \n"                           

      "    uniform highp   vec4   light_POSITION_01;                                                           \n"                           
      "    uniform         mat4   mvpMatrix;                                                                   \n"                           
      "    uniform         mat4   lightMatrix;                                                                 \n"                           

      "    attribute       vec4   position;                                                                    \n"                           
      "    attribute       vec3   normal;                                                                      \n"         
      "    attribute       vec3   tangent;                                                                     \n"             
      "    attribute       vec2   texture;                                                                     \n"                           

      "    varying highp vec4   lightPosition_PASS;                                                            \n"                           

      "    varying highp vec3   EyeDir;                                                                        \n"   
      "    varying highp vec2   varTexcoord;                                                                   \n"                           

      "    vec3 view;                                                                                          \n"    

      "    void main()                                                                                         \n"                           
      "    {                                                                                                   \n"                           
      
      "        vec3 m_Tangent = -vec3(mvpMatrix * vec4(tangent, 0.0));                                          \n" 
      "        vec3 m_Normal  = -vec3(mvpMatrix * vec4(normal, 0.0));                                            \n" 
      
      "        vec3 m_BiNormal = cross(m_Normal, m_Tangent);                                                    \n"  
  
      "        vec3 m_Vector = (lightMatrix * position).xyz;                                                     \n" 

      "        vec3  dirEye   = vec3(0.0, 0.0, 0.0) - m_Vector;                                                \n" 
                                              
      "        EyeDir.x = dot(m_Tangent, dirEye);                                                              \n" 
      "        EyeDir.y = dot(m_BiNormal , dirEye);                                                           \n" 
      "        EyeDir.z = dot(m_Normal , dirEye);                                                              \n"   
      
//------------------------------------------------------------------------------------------------------------------------      
      "        lightPosition_PASS = normalize(lightMatrix * light_POSITION_01);                                \n"                           

      "        varTexcoord        = texture;                                                                   \n"                           

      "        gl_Position        = mvpMatrix * position;                                                      \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      cube_relief_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(cube_relief_SHADER_VERTEX, 1, &vertexSource_cube_relief, NULL);                                                                        
      glCompileShader(cube_relief_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_cube_relief =                                                                                                            

      " #ifdef GL_ES                                                                                                                               \n"                       
      " #else                                                                                                                                      \n"                       
      " #define highp                                                                                                                              \n"                       
      " #endif                                                                                                                                     \n"                       

      "    uniform sampler2D     Texture1;                                                                                                         \n"                       
      "    uniform sampler2D     NormalMap;                                                                                                        \n"                       
      "    uniform sampler2D     HeightMap;                                                                                                        \n"       
      "    uniform highp float   shininess;                                                                                                        \n"                       
      "    uniform highp float   attenuation;                                                                                                      \n"                       

      "    varying highp vec4    lightPosition_PASS;                                                                                               \n"                       

      "    varying highp vec3    EyeDir;                                                                                                           \n"         
      
      "    varying highp vec2    varTexcoord;                                                                                                      \n"                       

      "            highp float   NdotL1;                                                                                                           \n"                       
      "            highp vec3    normal;                                                                                                           \n"                       
      "            highp vec3    NormalTex;                                                                                                        \n"                       


      "     void main()                                                                                                                            \n"                       
      "     {                                                                                                                                      \n"                       
                      
      "         vec3 EyeT       = normalize(EyeDir);                                                                                               \n"  
      "         vec4 Offset     = texture2D(HeightMap, varTexcoord. xy);                                                                               \n"  
      "         Offset          = Offset * shininess - attenuation;                                                                                            \n" 
      "         vec2 TexCoords  = Offset.xy * EyeT.xy + varTexcoord;                                                                               \n" 
  
      //------------------------------------------------------------------------------------------------------------------------
      
      "         NormalTex   =  texture2D(NormalMap,  TexCoords.xy).xyz;                                                                             \n"                       
      "         NormalTex             = (NormalTex - 0.5);                                                                                         \n"                       
      "         normal                =  normalize(NormalTex);                                                                                     \n"      
      "         NdotL1                =  dot(normal, lightPosition_PASS.xyz);                                                                      \n"                       

      //------------------------------------------------------------------------------------------------------------------------      
      
      "         gl_FragColor          =  texture2D(Texture1, TexCoords.xy) *  0.0                                                                \n"                       

      "                               +  texture2D(Texture1, TexCoords.xy) * NdotL1* 1.0                                       \n"                       

      "                               +  texture2D(Texture1, TexCoords.xy) * pow(NdotL1, 50.0) * vec4(2.0, 1.0, .1, 1.0)*0.0;                       \n"                       

      "    }\n";    
*/



      //---------------------------------------------------------------------                                                                         
      cube_relief_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(cube_relief_SHADER_FRAGMENT, 1, &fragmentSource_cube_relief, NULL);                                                                          
      glCompileShader(cube_relief_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(cube_relief_SHADER, cube_relief_SHADER_VERTEX);                                                                                              
      glAttachShader(cube_relief_SHADER, cube_relief_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(cube_relief_SHADER, 0, "position");                                                                                            
      glBindAttribLocation(cube_relief_SHADER, 1, "normal");       
      glBindAttribLocation(cube_relief_SHADER, 2, "tangent");         
      glBindAttribLocation(cube_relief_SHADER, 3, "texture");                                                                                             
      //------------------------------------------------                                                                                              
      glLinkProgram(cube_relief_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(cube_relief_SHADER, cube_relief_SHADER_VERTEX);                                                                                              
      glDetachShader(cube_relief_SHADER, cube_relief_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(cube_relief_SHADER_VERTEX);                                                                                                            
      glDeleteShader(cube_relief_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_cube_relief                   = glGetUniformLocation(cube_relief_SHADER,   "mvpMatrix");                                              
      UNIFORM_MODELVIEW_cube_relief                       = glGetUniformLocation(cube_relief_SHADER,   "mvMatrix");        
      UNIFORM_LIGHT_MATRIX_cube_relief                    = glGetUniformLocation(cube_relief_SHADER,   "lightMatrix");
      UNIFORM_linearTransform_cube_relief                 = glGetUniformLocation(cube_relief_SHADER,   "linearTransform");                                                  
      UNIFORM_LIGHT_POSITION_01_cube_relief               = glGetUniformLocation(cube_relief_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_cube_relief                       = glGetUniformLocation(cube_relief_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_cube_relief                     = glGetUniformLocation(cube_relief_SHADER,   "attenuation");
      UNIFORM_TEXTURE_HEIGHT_cube_relief                  = glGetUniformLocation(cube_relief_SHADER,   "HeightMap");                                                      
      UNIFORM_TEXTURE_DOT3_cube_relief                    = glGetUniformLocation(cube_relief_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_cube_relief                         = glGetUniformLocation(cube_relief_SHADER,   "Texture1");                                               
      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                
      //------------------------------------------------------------------------------------------                                              
      #ifdef __APPLE__                                                                                                                          
      filePathName = [[NSBundle mainBundle] pathForResource:@"cube_relief_DOT3" ofType:@"bmp"];                                                  
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &cube_relief_NORMALMAP);                                                                                                     
      glBindTexture(GL_TEXTURE_2D, cube_relief_NORMALMAP);                                                                                          
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      //---------------------                                                                                                                   
      filePathName = [[NSBundle mainBundle] pathForResource:@"cube_relief" ofType:@"png"];                                                       
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &cube_relief_TEXTUREMAP);                                                                                                       
      glBindTexture(GL_TEXTURE_2D, cube_relief_TEXTUREMAP);                                                                                            
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------                                              
      #ifdef WIN32                                                                                                                            
      loadTexture("_MODEL_FOLDERS_/cube_relief/height.png",             cube_relief_HEIGHT);         
      loadTexture("_MODEL_FOLDERS_/cube_relief/cube_relief_DOT3.bmp",          cube_relief_NORMALMAP);                                                      
      loadTexture("_MODEL_FOLDERS_/cube_relief/cube_relief.png",               cube_relief_TEXTUREMAP);                                                        
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "cube_relief.cpp"                                                                                                                
      glGenBuffers(1,              &cube_relief_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, cube_relief_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(cube_relief), cube_relief, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //--------------------------------------------------------------------------------------------------------------------     
      #include    "cube_relief_INDEX.cpp" 
      glGenBuffers(1, &cube_relief_INDEX_VBO);                       
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cube_relief_INDEX_VBO);                   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_relief_INDEX), cube_relief_INDEX, GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);      
      //=================================================================================================================================       




