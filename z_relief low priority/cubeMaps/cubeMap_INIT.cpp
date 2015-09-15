
    //AUX_RGBImageRec *pTextureImage = NULL;

	//glGenTextures(1, &cubemapTexture[0]);
	//glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture[0]);

//===========================================================================================================================================
/*		pTextureImage = auxDIBImageLoad("cubeMaps/Terrain_posx.bmp");

        if(pTextureImage != NULL) 
        {
              glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGB , pTextureImage->sizeX, pTextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pTextureImage->data);
        }
        if(pTextureImage) 
        {
             if( pTextureImage->data)
				free(pTextureImage->data);
			    free(pTextureImage);
		}
*/
    char textName_POSX[] = "cubeMaps/Terrain_posx.png";	
    char textName_NEGX[] = "cubeMaps/Terrain_negx.png";	
    char textName_POSY[] = "cubeMaps/Terrain_posy.png";    
    char textName_NEGY[] = "cubeMaps/Terrain_negy.png";	
    char textName_POSZ[] = "cubeMaps/Terrain_posz.png";	
    char textName_NEGZ[] = "cubeMaps/Terrain_negz.png";    
    
    FREE_IMAGE_FORMAT fifmt;
    FIBITMAP *dib;
    FIBITMAP *temp = dib;    
    
    //------------------------------------------------------------------------------------------
    
    fifmt = FreeImage_GetFileType(textName_POSX, 0);
    dib = FreeImage_Load(fifmt,   textName_POSX, 0);
    temp = dib;
    
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        free(pixels);
        FreeImage_Unload(dib);
	}
    //------------------------------------------------------------------------------------------
    
    fifmt = FreeImage_GetFileType(textName_NEGX, 0);
    dib = FreeImage_Load(fifmt,   textName_NEGX, 0);
    temp = dib;
    
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        free(pixels);
        FreeImage_Unload(dib);
	}
    //------------------------------------------------------------------------------------------
    
    fifmt = FreeImage_GetFileType(textName_POSY, 0);
    dib = FreeImage_Load(fifmt,   textName_POSY, 0);
    temp = dib;
    
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        free(pixels);
        FreeImage_Unload(dib);
	}
    //------------------------------------------------------------------------------------------
    
    fifmt = FreeImage_GetFileType(textName_NEGY, 0);
    dib = FreeImage_Load(fifmt,   textName_NEGY, 0);
    temp = dib;
    
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        free(pixels);
        FreeImage_Unload(dib);
	}

    //------------------------------------------------------------------------------------------
    
    fifmt = FreeImage_GetFileType(textName_POSZ, 0);
    dib = FreeImage_Load(fifmt,   textName_POSZ, 0);
    temp = dib;
    
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        free(pixels);
        FreeImage_Unload(dib);
	}
    //------------------------------------------------------------------------------------------
    
    fifmt = FreeImage_GetFileType(textName_NEGZ, 0);
    dib = FreeImage_Load(fifmt,   textName_NEGZ, 0);
    temp = dib;
    
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        free(pixels);
        FreeImage_Unload(dib);
	}






//===========================================================================================================================================   
/*		pTextureImage = auxDIBImageLoad("cubeMaps/Terrain_negx.bmp");

		if(pTextureImage != NULL) 
        {
              glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGB , pTextureImage->sizeX, pTextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pTextureImage->data);
        }
        if(pTextureImage) 
        {
             if( pTextureImage->data)
				free(pTextureImage->data);
			    free(pTextureImage);
		}*/
//===========================================================================================================================================   
/*	  	pTextureImage = auxDIBImageLoad("cubeMaps/Terrain_posy.bmp");

        if(pTextureImage != NULL) 
        {
              glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGB , pTextureImage->sizeX, pTextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pTextureImage->data);    
        }
        if(pTextureImage) 
        {
             if( pTextureImage->data)
				free(pTextureImage->data);
			    free(pTextureImage);
		}*/
//===========================================================================================================================================   
/*        pTextureImage = auxDIBImageLoad("cubeMaps/Terrain_negy.bmp");

        if(pTextureImage != NULL) 
        {
              glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGB , pTextureImage->sizeX, pTextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pTextureImage->data);   
        }
        if(pTextureImage) 
        {
             if( pTextureImage->data)
				free(pTextureImage->data);
			    free(pTextureImage);
		}*/
//===========================================================================================================================================   
/*        pTextureImage = auxDIBImageLoad("cubeMaps/Terrain_posz.bmp");

		if(pTextureImage != NULL) 
        {
              glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGB , pTextureImage->sizeX, pTextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pTextureImage->data);   
        }
        if(pTextureImage) 
        {
             if( pTextureImage->data)
				free(pTextureImage->data);
			    free(pTextureImage);
		}*/
//===========================================================================================================================================   
/*	    pTextureImage = auxDIBImageLoad("cubeMaps/Terrain_negx.bmp");

        if(pTextureImage != NULL) 
        {
              glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGB , pTextureImage->sizeX, pTextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pTextureImage->data);
        }
        if(pTextureImage) 
        {
             if( pTextureImage->data)
				free(pTextureImage->data);
			    free(pTextureImage);
		}*/
//===========================================================================================================================================   
     
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER,    GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER,    GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S,        GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T,        GL_CLAMP_TO_EDGE);    
	//glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_GENERATE_MIPMAP_SGIS,  GL_TRUE );    

/*    
    glTexParameteri( GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_S,             GL_CLAMP_TO_EDGE );
	glTexParameteri( GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_T,             GL_CLAMP_TO_EDGE );
	glTexParameteri( GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_R,             GL_CLAMP_TO_EDGE );
	glTexParameteri( GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_MIN_FILTER,         GL_LINEAR_MIPMAP_LINEAR );
	glTexParameteri( GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_MAG_FILTER,         GL_LINEAR );
	glTexParameteri( GL_TEXTURE_CUBE_MAP_ARB, GL_GENERATE_MIPMAP_SGIS,       GL_TRUE );
	glTexParameterf( GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_MAX_ANISOTROPY_EXT, 16.0);   
*/
