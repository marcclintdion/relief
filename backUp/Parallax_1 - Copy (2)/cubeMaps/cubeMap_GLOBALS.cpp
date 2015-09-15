GLuint        CUBE_MAPPING_textureID;

GLuint   cubemapTexture[1];

GLuint   g_uiCubeMapConstants[6] = 
{
    GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB,
	GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB,
	GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB
};

char *g_cCubemaps[6] = 
{

	"cubeMaps/Terrain_posx.bmp",
	"cubeMaps/Terrain_negx.bmp",
	"cubeMaps/Terrain_posy.bmp",
	"cubeMaps/Terrain_negy.bmp",
	"cubeMaps/Terrain_posz.bmp",
	"cubeMaps/Terrain_negz.bmp"
};
