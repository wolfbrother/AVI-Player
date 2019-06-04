package com.apress.aviplayer;

import java.io.IOException;

import android.app.Activity;
import android.app.AlertDialog;

/**
 * Player activity.
 * 
 * @author Onur Cinar
 */
public abstract class AbstractPlayerActivity extends Activity {
	/** AVI file name extra. */
	public static final String EXTRA_FILE_NAME = 
			"com.apress.aviplayer.EXTRA_FILE_NAME";
	
	/** AVI video file descriptor. */
	protected long avi = 0;
	
	/**
	 * On start.
	 */
	protected void onStart() {
		super.onStart();
		
		// Open the AVI file
		try {
			avi = open(getFileName());
		} catch (IOException e) {
			new AlertDialog.Builder(this)
					.setTitle(R.string.error_alert_title)
					.setMessage(e.getMessage())
					.show();
		}
	}

	/**
	 * On stop.
	 */
	protected void onStop() {
		super.onStop();
		
		// If the AVI video is open
		if (0 != avi) {
			// Close the file descriptor
			close(avi);
			avi = 0;
		}
	}

	/**
	 * Gets the AVI video file name.
	 * 
	 * @return file name.
	 */
	protected String getFileName() {
		return getIntent().getExtras().getString(EXTRA_FILE_NAME);
	}
	
	/**
	 * Opens the given AVI file and returns a file descriptor.
	 * 
	 * @param fileName file name.
	 * @return file descriptor.
	 * @throws IOException
	 */
	protected native static long open(String fileName) throws IOException;
	
	/**
	 * Get the video width.
	 * 
	 * @param avi file descriptor.
	 * @return video width.
	 */
	protected native static int getWidth(long avi);
	
	/**
	 * Get the video height.
	 * 
	 * @param avi file descriptor.
	 * @return video height.
	 */
	protected native static int getHeight(long avi);
	
	/**
	 * Gets the frame rate.
	 * 
	 * @param avi file descriptor.
	 * @return frame rate.
	 */
	protected native static double getFrameRate(long avi);

	/**
	 * Closes the given AVI file based on given file descriptor.
	 * 
	 * @param avi file descriptor.
	 */
	protected native static void close(long avi);
	
	static {
		System.loadLibrary("AVIPlayer");
	}
}
