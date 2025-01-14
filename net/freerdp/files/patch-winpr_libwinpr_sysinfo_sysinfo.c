--- winpr/libwinpr/sysinfo/sysinfo.c.orig	2023-12-14 18:03:49 UTC
+++ winpr/libwinpr/sysinfo/sysinfo.c
@@ -782,13 +782,15 @@ BOOL IsProcessorFeaturePresent(DWORD ProcessorFeature)
 			break;
 	}
 
-#elif defined(__APPLE__) // __linux__
+#else // __linux__
 
 	switch (ProcessorFeature)
 	{
 		case PF_ARM_NEON_INSTRUCTIONS_AVAILABLE:
 		case PF_ARM_NEON:
+#ifdef __ARM_NEON
 			ret = TRUE;
+#endif
 			break;
 	}
 
