/*!  \file kfbxtypes.h
 */

#ifndef _KFbxTypes_h
#define _KFbxTypes_h

/**************************************************************************************

 Copyright ?2001 - 2008 Autodesk, Inc. and/or its licensors.
 All Rights Reserved.

 The coded instructions, statements, computer programs, and/or related material 
 (collectively the "Data") in these files contain unpublished information 
 proprietary to Autodesk, Inc. and/or its licensors, which is protected by 
 Canada and United States of America federal copyright law and by international 
 treaties. 
 
 The Data may not be disclosed or distributed to third parties, in whole or in
 part, without the prior written consent of Autodesk, Inc. ("Autodesk").

 THE DATA IS PROVIDED "AS IS" AND WITHOUT WARRANTY.
 ALL WARRANTIES ARE EXPRESSLY EXCLUDED AND DISCLAIMED. AUTODESK MAKES NO
 WARRANTY OF ANY KIND WITH RESPECT TO THE DATA, EXPRESS, IMPLIED OR ARISING
 BY CUSTOM OR TRADE USAGE, AND DISCLAIMS ANY IMPLIED WARRANTIES OF TITLE, 
 NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE OR USE. 
 WITHOUT LIMITING THE FOREGOING, AUTODESK DOES NOT WARRANT THAT THE OPERATION
 OF THE DATA WILL BE UNINTERRUPTED OR ERROR FREE. 
 
 IN NO EVENT SHALL AUTODESK, ITS AFFILIATES, PARENT COMPANIES, LICENSORS
 OR SUPPLIERS ("AUTODESK GROUP") BE LIABLE FOR ANY LOSSES, DAMAGES OR EXPENSES
 OF ANY KIND (INCLUDING WITHOUT LIMITATION PUNITIVE OR MULTIPLE DAMAGES OR OTHER
 SPECIAL, DIRECT, INDIRECT, EXEMPLARY, INCIDENTAL, LOSS OF PROFITS, REVENUE
 OR DATA, COST OF COVER OR CONSEQUENTIAL LOSSES OR DAMAGES OF ANY KIND),
 HOWEVER CAUSED, AND REGARDLESS OF THE THEORY OF LIABILITY, WHETHER DERIVED
 FROM CONTRACT, TORT (INCLUDING, BUT NOT LIMITED TO, NEGLIGENCE), OR OTHERWISE,
 ARISING OUT OF OR RELATING TO THE DATA OR ITS USE OR ANY OTHER PERFORMANCE,
 WHETHER OR NOT AUTODESK HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH LOSS
 OR DAMAGE. 

**************************************************************************************/

#include <kaydaradef.h>
#ifndef KFBX_DLL
    #define KFBX_DLL K_DLLIMPORT
#endif

#ifndef MB_FBXSDK
#include <kbaselib_nsuse.h>
#endif
#include <kbaselib_forward.h>
#include <klib/kdebug.h>
#include <klib/kstring.h>
#include <klib/ktime.h>

#include <kfbxplugins/kfbxcolor.h>
#include <kfbxplugins/kfbxsystemunit.h>
#include <fbxfilesdk_nsbegin.h>

    class   KFbxSdkManager;

    // Type definitions
    typedef enum {
        eUNIDENTIFIED,
        eBOOL1,
        eINTEGER1,
        eFLOAT1,
        eDOUBLE1,
        eDOUBLE2,
        eDOUBLE3,
        eDOUBLE4,
        eDOUBLE44,
        eENUM,
        eSTRING,
        eTIME,
        eREFERENCE,  // used as a port entry to reference object or properties
        eBLOB,
        eDISTANCE,
        eDATETIME,
        eMAX_TYPES,
    } EFbxType;

    // Base Type for vectors
    template<class T> class fbxVectorTemplate2 {
        public:
            inline fbxVectorTemplate2()                      { *this = 0;  }
            inline fbxVectorTemplate2(T pValue)              { *this = pValue;  }
            inline fbxVectorTemplate2(T pData0,T pData1)    { mData[0] = pData0; mData[1] = pData1; }
            inline ~fbxVectorTemplate2() {}
        public:
            inline T &operator[](int pIndex) { return mData[pIndex]; }
            inline T const&operator[](int pIndex) const { return mData[pIndex]; }
            inline fbxVectorTemplate2<T> &operator=(T const & pValue) { mData[0] = pValue; mData[1] = pValue; return *this; }
            inline fbxVectorTemplate2<T> &operator=(const fbxVectorTemplate2<T> & pRHS) { mData[0] = pRHS.mData[0]; mData[1] = pRHS.mData[1]; return *this; }
            inline bool operator==(fbxVectorTemplate2<T> const & pRHS) const { return ((mData[0] == pRHS.mData[0]) && (mData[1] == pRHS.mData[1])); }
            inline bool operator!=(fbxVectorTemplate2<T> const & pRHS) const { return !operator==( pRHS ); }

        operator T*() { return mData; }
        operator T const*() const { return mData; }

        public:
            T mData[2];
    };

    template<class T> class fbxVectorTemplate3 {
        public:
            inline fbxVectorTemplate3()                          { *this = 0;  }
            inline fbxVectorTemplate3(T pValue)                  { *this = pValue;  }
            inline fbxVectorTemplate3(T pData0,T pData1,T pData2) { mData[0] = pData0; mData[1] = pData1; mData[2] = pData2;  }
            inline ~fbxVectorTemplate3() {}
        public:
            inline T &operator[](int pIndex) { return mData[pIndex]; }
            inline T const&operator[](int pIndex) const { return mData[pIndex]; }
            inline fbxVectorTemplate3<T> &operator=(int pValue)      { mData[0] = pValue; mData[1] = pValue; mData[2] = pValue; return *this; }
            inline fbxVectorTemplate3<T> &operator=(T const &pValue) { mData[0] = pValue; mData[1] = pValue; mData[2] = pValue; return *this; }
            inline fbxVectorTemplate3<T> &operator=(const fbxVectorTemplate3<T> & pRHS) { mData[0] = pRHS.mData[0]; mData[1] = pRHS.mData[1]; mData[2] = pRHS.mData[2]; return *this; }
            inline bool operator==(fbxVectorTemplate3<T> const & pRHS) const { return ((mData[0] == pRHS.mData[0]) && (mData[1] == pRHS.mData[1]) && (mData[2] == pRHS.mData[2])); }
            inline bool operator!=(fbxVectorTemplate3<T> const & pRHS) const { return !operator==(pRHS); }

            inline operator T*() { return mData; }
            inline operator T const*() const { return mData; }

        public:
            T mData[3];
    };

    template<class T> class fbxVectorTemplate4 {
        public:
            inline fbxVectorTemplate4()                                     { *this = 0; }
            inline fbxVectorTemplate4(T pValue)                             { *this = pValue; }
            inline fbxVectorTemplate4(T pData0,T pData1,T pData2,T pData3)  { mData[0] = pData0; mData[1] = pData1; mData[2] = pData2; mData[3] = pData3;   }
            inline ~fbxVectorTemplate4() {}
        public:
            inline T &operator[](int pIndex) { return mData[pIndex]; }
            inline operator fbxVectorTemplate3<T>& () const { return *((fbxVectorTemplate3<T> *)this); }
            inline T const&operator[](int pIndex) const { return mData[pIndex]; }
            inline fbxVectorTemplate4<T> &operator=(int pValue)                          { mData[0] = pValue; mData[1] = pValue; mData[2] = pValue; mData[3] = pValue; return *this; }
            inline fbxVectorTemplate4<T> &operator=(T const &pValue)                     { mData[0] = pValue; mData[1] = pValue; mData[2] = pValue; mData[3] = pValue; return *this; }
            inline fbxVectorTemplate4<T> &operator=(fbxVectorTemplate3<T> const &pValue) { mData[0] = pValue[0]; mData[1] = pValue[1]; mData[2] = pValue[2]; return *this; }
            inline fbxVectorTemplate4<T> &operator=(const fbxVectorTemplate4<T> & pRHS) { mData[0] = pRHS.mData[0]; mData[1] = pRHS.mData[1]; mData[2] = pRHS.mData[2]; mData[3] = pRHS.mData[3]; return *this; }
            inline bool operator==(fbxVectorTemplate4<T> const & pRHS) const { return ((mData[0] == pRHS.mData[0]) && (mData[1] == pRHS.mData[1]) && (mData[2] == pRHS.mData[2]) && (mData[3] == pRHS.mData[3])); }
            inline bool operator!=(fbxVectorTemplate4<T> const & pRHS) const { return !operator==( pRHS ); }
            inline operator T*() { return mData; }
            inline operator T const*() const { return mData; }

        public:
            T mData[4];
    };
    

	/** FBX SDK blob class. 
	  * Uninitialized data of a specified size, to be filled by the user.
	  * \nosubgrouping
	  */
    class KFBX_DLL fbxBlob {
        public:
			/**
			  * \name Constructors and Destructor
			  */
			//@{

			//! Constructor.  Set attributes to 0.
            inline fbxBlob()                              { mData = 0; mSize = 0; mRefCount = 0; }

			/** Constructor.  Construct a buffer with uninitialized data of a specfified size, to be filled by the user.
			  * \param pSize                Buffer size.
			  */
                   fbxBlob(int pSize);

		    /** Copy constructor.
			  * \param pRHS                 The blob to be copied to this blob.
			  */
            inline fbxBlob(const fbxBlob & pRHS)          { mData = 0; mSize = 0; mRefCount = 0; *this = pRHS; }

			/** Constructor.
			  * \param pData                The data to be filled in the buffer.
			  * \param pSize                Buffer size.
			  */
            inline fbxBlob(const void * pData, int pSize) { mData = 0; mSize = 0; mRefCount = 0; Assign(pData,pSize); }

			//! Destructor
            ~fbxBlob();

			//@}
        public:
			/**
			  * \name Assignment.
			  */
			//@{

			/** Share the buffer of the specified blob with this blob. 
			  * \param pValue               The blob whose buffer is shared with this blob.
			  * \return                     This blob.
			  */
                   fbxBlob &operator=(fbxBlob const &pValue);

		   /** Copy the data in the buffer.
		     * \param pData                 The buffer to be copied data from.
			 * \param pSize                 Buffer size.
		     */
                   void Assign(const void * pData, int pSize);  // Always makes a copy.
			//@}

            /**
			  * \name Boolean operation
			  */
		    //@{

		    /** Equivalence operator
             * \param pRHS                  The blob to be compared with this blob.
			 * \return                      \c True, if the two blobs are equal, \c false otherwise.
		     */
                   bool operator==(fbxBlob const & pRHS) const; // Compare the contents.

            /** Non-equivalence operator
              * \param pRHS                  The blob to be compared with this blob.
			  * \return                      \c True, if the two blobs are unequal, otherwise false.
		      */
            inline bool operator!=(fbxBlob const & pRHS) const { return !operator==( pRHS ); }
			//@}

			 //!Make a copy if the reference count > 1 (i.e. if the buffer is shared).
                   void * Modify(); 

		     /**
			   * \name Access
			   */
			 //@{
		    
		     /** Retrieve the buffer pointer.
			   * \return                      The buffer pointer.
			   */
                   const void * Access() const { return mData; }

		    /** Retrieve the buffer size
			  * \return                       The buffer size.
			  */
                   inline int Size() const { return mSize; }
			 //@}

		    //! Free the memory if this blob is the last one to hold it.
                   void Clear(); 

        protected:
            int *   mRefCount;
            void *  mData;
            int     mSize;

    };

	/** FBX SDK distance class.
	  * \nosubgrouping
      */
    class KFBX_DLL fbxDistance {
        public:
			/**
			  * \name Constructors and Destructor
			  */
			//@{
            
			//! Default constructor.
            fbxDistance(): mUnit(1.0), mValue(0.0) {  }

			/** Constructor with default values.
			  * \param pValue      Value of distance using the measurement unit.
			  * \param pUnit       Unit of measurement.
			  */
            fbxDistance(float pValue, KFbxSystemUnit pUnit): mUnit(1.0), mValue(0.0) {
                mValue = pValue;
                mUnit = pUnit;
            }
            
			/** Constructor.    
			  * \param pValue      Value of distance using the measurement unit.
			  * \param pUnit       Unit of measurement.
			  * \remarks           This constructor will conver string to KFbxSystemUnit.
			  */
            fbxDistance(float pValue, const char* pUnit);

			//! Destructor.
            ~fbxDistance() {  }

			//@}
        public:

            /**
			  * \name Assignment operation
			  */
            //@{
            
			/** Assign operator
			  * \param pValue       The distance to be assigned to this distance.
			  * \return             This distance.
			  */
            fbxDistance &operator=(fbxDistance const& pValue) {
                        mValue = pValue.mValue;
                        mUnit = pValue.mUnit;
                        return *this;
            }
			//@}
            
			/**
			  * \name boolean operation
			  */
			//@{

			/** Equivalence operator.
			  * \param pRHS          The distance to be compared with this distance.
			  * \return              \c True, if the two distances are equal, \c false otherwise.
			  */
            bool operator==(fbxDistance const & pRHS) const { return ( (mValue == pRHS.mValue) && (mUnit == pRHS.mUnit) ); }

			/** Non-equivalence operator.
			  * \param pRHS          The distance to be compared with this distance.
			  * \return              \c True, if the two distances are unequal, \c false otherwise.
			  */
            bool operator!=(fbxDistance const& pRHS) const { return !operator==(pRHS); }
			//@}

			
            KString const unitName() const    {   return mUnit.GetScaleFactorAsString();    }

			/**
			  * \name Access
			  */
			//@{

			/** Retrieve the measurement unit
			  * \return             The measure unit of the distance.
			  */
            KFbxSystemUnit const unit() const   {   return mUnit;  }

			/** Retrieve the value of distance using the measurement unit.
			  * \return             The value of distance using the measurement unit.   
			  */
            float const value() const   {   return mValue;  }
			//@}

            /** Get the value of distance when converting this measurement unit to inch.
			  * \return             The value of distance when converting this measurement unit to inch.
			  */
            float const internalValue() const {
                KFbxSystemUnit internalUnit(KFbxSystemUnit::Inch);
                float internalValue = (float)(mValue * mUnit.GetConversionFactorTo(internalUnit));
                return internalValue;
            }

			/** Get the value of distance when converting this measurement unit to the specified measurement unit.
			  * \param pUnit       The measurement unit to be converted to.
			  * \return            The value of distance when using the specified measurement unit.
			  */
            float const valueAs( KFbxSystemUnit const& pUnit ) const
            {
                float convertedValue = (float)(mValue * mUnit.GetConversionFactorTo(pUnit));
                return convertedValue;
            }

        private:
            float               mValue;
            KFbxSystemUnit      mUnit;
        };

    
       
    

	/**	FBX SDK date&time class.
	  * Property used to store date and time information; not related to a KTime, which is
	  * used for film-related operations.
	  * The date and time property does not make any provisions for UTC, GMT or local
	  * zones; this is entirely up to client code to know what they are dealing with.
      * \nosubgrouping
      */
    class KFBX_DLL fbxDateTime
    {
    public:
        kShort mMillisecond;            // 0-999
        kShort mYear;                   // No check

        kByte  mMonth;                  // 1-12
        kByte  mDay;                    // 1-31; no check with regards to the month
        kByte  mHour;                   // 0-23
        kByte  mMinute;                 // 0-59
        kByte  mSecond;                 // 0-59

    public:
		/**
		  *\name Constructors
		  */
		//@{
       
		//! Default constructor. Set attributes to 0.   
        fbxDateTime() { Clear(); }

		/** Constructor.
		  *\param pDay           Day
		  *\param pMonth         Month
		  *\param pYear          Year
		  *\param pHour          Hour
		  *\param pMin           Minute
		  *\param pSec           Second
		  *\param pMillisecond   Millisecond
		  */
        fbxDateTime(int pDay, int pMonth, int pYear, int pHour, int pMin, int pSec, int pMillisecond = 0);

		//@}

		/**
		  * \name Boolean operation
		  */
		//@{

        /** Equivalence operator.
		  *\param pRHS              The date&time to be compared with this date&time.
		  *\return              \c True, if the two date&time are equal, \c false otherwise.
		  */
        bool operator==(const fbxDateTime& pRHS) const;

		/** Non-equivalence operator
		  *\param pRHS         The date&time to be compared with this date&time.
		  *\return             \c True, if the two date&time are not equal, \c false otherwise.
		  */
        bool operator!=(const fbxDateTime& pRHS) const
        {
            return !(*this == pRHS); 
        }
		//@}

        //! Set the attributes to 0.
        void Clear()
        {
            mMillisecond = mYear = 0;
            mMonth = mDay = mHour = mMinute = mSecond = 0;
        }

		
        /** Validates each field is within a normal range (month is 1-12, etc).
		  * \return               \c True, if each field is within a normal range, \c false otherwise.
		  */
        bool isValid() const;

	
       
		/**
		  * \name Access
		  */
        //@{
		/** Set the date.
		  * \param pDay          Day to be set.
		  * \param pMonth        Month to be set.
		  * \param pYear         Year to be set.
		  */
        void setDate(int pDay, int pMonth, int pYear);

		/** Set the time. 
		  * \param pHour         Hour to be set.
		  * \param pMin          Minute to be set.
		  * \param pSec          Second to be set.
		  * \param pMillisecond  Millisecond to be set.
		  */
        void setTime(int pHour, int pMin, int pSec, int pMillisecond = 0);
		//@}


		/**
		  * \name  Operation with string
		  */

		//@{

		/** Get the string format from this date&time.
		  * \return              The string format got from this date&time.
		  */
        KString toString() const;

        /** Get date&time from the string format.
		  * \return             \c True, if get date&time from the string format successfully, \c false otherwise.
		  * \remark             ! This will only work with the format returned by toString(); if the format
          *                     is not the same will return 'false' and the content of this object will
          *                     remain unchanged.
		  */
        bool fromString(const char*);
		//@}
       
		/** Get date&time from current date&time of GMT.
		  * \return             The date&time equal to current date&time of GMT.         
		  */
        static fbxDateTime currentDateTimeGMT();
    };

    // Corresponding C Types
    typedef bool                                fbxBool1;
    typedef int                                 fbxInteger1;
    typedef float                               fbxFloat1;
    typedef double                              fbxDouble1;
    typedef fbxVectorTemplate2<double>          fbxDouble2;
    typedef fbxVectorTemplate3<double>          fbxDouble3;
    typedef fbxVectorTemplate4<double>          fbxDouble4;
    typedef fbxVectorTemplate4<fbxDouble4>      fbxDouble44;
    typedef int                                 fbxEnum;
    typedef KString                             fbxString;
    typedef KTime                               fbxTime;
    typedef fbxBlob                             KFbxBlob;
    class                                       fbxReference {}; // void type for references
    typedef fbxDistance                         KFbxDistance;

    // Type memory footprint
    const size_t FbxTypeSizeOf[eMAX_TYPES] = {
        0,
        sizeof(fbxBool1),
        sizeof(fbxInteger1),
        sizeof(fbxFloat1),
        sizeof(fbxDouble1),
        sizeof(fbxDouble2),
        sizeof(fbxDouble3),
        sizeof(fbxDouble4),
        sizeof(fbxDouble44),
        sizeof(fbxEnum),
        sizeof(fbxString),
        sizeof(fbxTime),
        sizeof(fbxReference),
        sizeof(fbxBlob),
        sizeof(fbxDistance),
        sizeof(fbxDateTime)
    };

    // Type management for properties
    template <class T> inline EFbxType FbxTypeOf( T const &pItem ) { K_ASSERT_MSG_NOW("Unknown type" ); return eUNIDENTIFIED; }

    inline EFbxType FbxTypeOf( fbxBool1 const &pItem )      { return eBOOL1;    }
    inline EFbxType FbxTypeOf( fbxInteger1 const &pItem )   { return eINTEGER1; }
    inline EFbxType FbxTypeOf( fbxFloat1 const &pItem )     { return eFLOAT1;   }
    inline EFbxType FbxTypeOf( fbxDouble1 const &pItem )    { return eDOUBLE1;  }
    inline EFbxType FbxTypeOf( fbxDouble2 const &pItem )    { return eDOUBLE2;  }
    inline EFbxType FbxTypeOf( fbxDouble3 const &pItem )    { return eDOUBLE3;  }
    inline EFbxType FbxTypeOf( fbxDouble4 const &pItem )    { return eDOUBLE4;  }
    inline EFbxType FbxTypeOf( fbxDouble44 const &pItem )   { return eDOUBLE44; }
//  inline EFbxType FbxTypeOf( fbxEnum const &pItem )       { return eENUM; }
    inline EFbxType FbxTypeOf( fbxString const &pItem )     { return eSTRING;   }
    inline EFbxType FbxTypeOf( fbxTime  const &pItem )      { return eTIME;      }
    inline EFbxType FbxTypeOf( fbxReference const &pItem )  { return eREFERENCE; }
    inline EFbxType FbxTypeOf( fbxBlob const &pItem )       { return eBLOB; }
    inline EFbxType FbxTypeOf( fbxDistance const &pItem)    { return eDISTANCE; }
    inline EFbxType FbxTypeOf( fbxDateTime const &pItem)    { return eDATETIME; }

    // To overcome VC6/net2002 compiler bugs I need a function with a different
    // prototype than FbxTypeOf( T const &pItem ) but rather that struggling to
    // find the correct prototype, we simply define a different function.
    // Since I need it in the LayerElement classes only to properly handle the
    // KFbxSurfaceMaterial*, KFbxTexure* and kReference* types, It is not a
    // big deal to have this duplicata of function. However, when the LayerElement
    // stuff is converted to properties, this set of function SHOULD be deleted.
    template <class T> inline EFbxType _FbxTypeOf( T* const &pItem) { return eREFERENCE; }
    inline EFbxType _FbxTypeOf( fbxBool1 const &pItem )     { return eBOOL1;    }
    inline EFbxType _FbxTypeOf( fbxInteger1 const &pItem )  { return eINTEGER1; }
    inline EFbxType _FbxTypeOf( fbxFloat1 const &pItem )    { return eFLOAT1;   }
    inline EFbxType _FbxTypeOf( fbxDouble1 const &pItem )   { return eDOUBLE1;  }
    inline EFbxType _FbxTypeOf( fbxDouble2 const &pItem )   { return eDOUBLE2;  }
    inline EFbxType _FbxTypeOf( fbxDouble3 const &pItem )   { return eDOUBLE3;  }
    inline EFbxType _FbxTypeOf( fbxDouble4 const &pItem )   { return eDOUBLE4;  }
    inline EFbxType _FbxTypeOf( fbxDouble44 const &pItem )  { return eDOUBLE44; }
//  inline EFbxType _FbxTypeOf( fbxEnum const &pItem )      { return eENUM; }
    inline EFbxType _FbxTypeOf( fbxString const &pItem )    { return eSTRING;   }
    inline EFbxType _FbxTypeOf( fbxTime const &pItem )      { return eTIME;      }
    inline EFbxType _FbxTypeOf( fbxReference const &pItem ) { return eREFERENCE; }
    inline EFbxType _FbxTypeOf( fbxBlob const &pItem )      { return eBLOB; }
    inline EFbxType _FbxTypeOf( KFbxColor   const &pItem )  { return eDOUBLE4; }
    inline EFbxType _FbxTypeOf( fbxDistance const &pItem )  { return eDISTANCE;  }
    inline EFbxType _FbxTypeOf( fbxDateTime const &pItem )  { return eDATETIME;  }

    // Additional types
    inline EFbxType FbxTypeOf( KFbxColor    const &pItem )  { return eDOUBLE4; }

    // internal type management
//  template< class T1,class T2,class T3 > inline bool internalfbxCopy1To3 ( T1 &pDst,T2 const &pSrc ) { pDst[0] = (T3)pSrc; pDst[1] = (T3)pSrc; pDst[2] = (T3)pSrc; return true; }
/*  template< class T1,class T2 > inline bool internalfbxCopy  ( T1 &pDst,T2 const &pSrc ) { pDst    = (T1)pSrc; return true; }
    template< class T1,class T2 > inline bool internalfbxCopy2 ( T1 &pDst,T2 const &pSrc ) { pDst[0] = (T1)pSrc[0]; pDst[1] = (T1)pSrc[1]; return true; }
    template< class T1,class T2 > inline bool internalfbxCopy3 ( T1 &pDst,T2 const &pSrc ) { pDst[0] = (T1)pSrc[0]; pDst[1] = (T1)pSrc[1]; pDst[2] = (T1)pSrc[2]; return true; }
    template< class T1,class T2 > inline bool internalfbxCopy4 ( T1 &pDst,T2 const &pSrc ) { pDst[0] = (T1)pSrc[0]; pDst[1] = (T1)pSrc[1]; pDst[2] = (T1)pSrc[2]; pDst[3] = (T1)pSrc[3]; return true; }
*/
    bool KFBX_DLL fbxCopyStr( fbxDouble1& pDst,  fbxString const& pSrc );
    bool KFBX_DLL fbxCopyStr( fbxBool1& pDst,    fbxString const& pSrc );
    bool KFBX_DLL fbxCopyStr( fbxInteger1& pDst, fbxString const& pSrc );

    // Copy types and conversions
    template< class T1,class T2 > inline bool fbxCopy ( T1 &pDst,T2 const &pSrc ) { K_ASSERT_MSG_NOW("Incompatible type assigment" ); return false; }

    // Copy Types and Conversions
    inline bool fbxCopy( fbxBool1 &pDst,fbxBool1 const &pSrc )          { pDst=pSrc; return true; }
    inline bool fbxCopy( fbxInteger1 &pDst,fbxInteger1 const &pSrc )    { pDst=pSrc; return true; }
    inline bool fbxCopy( fbxFloat1 &pDst,fbxFloat1 const &pSrc )        { pDst=pSrc; return true; }
    inline bool fbxCopy( fbxDouble1 &pDst,fbxDouble1 const &pSrc )      { pDst=pSrc; return true; }
    inline bool fbxCopy( fbxDouble2 &pDst,fbxDouble2 const &pSrc )      { pDst=pSrc; return true; }
    inline bool fbxCopy( fbxDouble3 &pDst,fbxDouble3 const &pSrc )      { pDst=pSrc; return true; }
    inline bool fbxCopy( fbxDouble4 &pDst,fbxDouble4 const &pSrc )      { pDst=pSrc; return true; }
    inline bool fbxCopy( fbxDouble44 &pDst,fbxDouble44 const &pSrc )    { pDst=pSrc; return true; }
//  inline bool fbxCopy( fbxEnum &pDst,fbxEnum const &pSrc )            { pDst=pSrc; return true; }
    inline bool fbxCopy( fbxString &pDst,fbxString const &pSrc )        { pDst=pSrc; return true; }
    inline bool fbxCopy( fbxTime &pDst,fbxTime const &pSrc )            { pDst=pSrc; return true; }
    inline bool fbxCopy( fbxReference &pDst,fbxReference const &pSrc )  { pDst=pSrc; return true; }
    inline bool fbxCopy( fbxBlob &pDst,fbxBlob const &pSrc )            { pDst=pSrc; return true; }
    inline bool fbxCopy( fbxDistance &pDst, fbxDistance const &pSrc )   { pDst=pSrc; return true; }
    inline bool fbxCopy( fbxDateTime &pDst, fbxDateTime const &pSrc )   { pDst=pSrc; return true; }

    // To FbxBool
//  inline bool fbxCopy( fbxBool1 &pDst,fbxBool1 const &pSrc )          { pDst   = (fbxBool1)pSrc; return true; }
    inline bool fbxCopy( fbxBool1 &pDst,fbxInteger1 const &pSrc )       { pDst   = pSrc == 0 ? false : true; return true; }
    inline bool fbxCopy( fbxBool1 &pDst,fbxFloat1 const &pSrc )         { pDst   = pSrc == 0.f ? false : true; return true; }
    inline bool fbxCopy( fbxBool1 &pDst,fbxDouble1 const &pSrc )        { pDst   = pSrc == 0. ? false : true; return true; }
    inline bool fbxCopy( fbxBool1 &pDst,fbxDouble2 const &pSrc )        { return false; }
    inline bool fbxCopy( fbxBool1 &pDst,fbxDouble3 const &pSrc )        { return false; }
    inline bool fbxCopy( fbxBool1 &pDst,fbxDouble4 const &pSrc )        { return false; }
    inline bool fbxCopy( fbxBool1 &pDst,fbxDouble44 const &pSrc )       { return false; }
//  inline bool fbxCopy( fbxBool1 &pDst,fbxEnum const &pSrc )           { return false; }
    inline bool fbxCopy( fbxBool1 &pDst,fbxString const &pSrc )         { return fbxCopyStr(pDst,pSrc); }
    inline bool fbxCopy( fbxBool1 &pDst,fbxTime const &pSrc )           { return false; }
    inline bool fbxCopy( fbxBool1 &pDst,fbxReference const &pSrc )      { return false; }
    inline bool fbxCopy( fbxBool1 &pDst,fbxBlob const &pSrc )           { return false; }
    inline bool fbxCopy( fbxBool1 &pDst, fbxDistance const &pSrc )      { return false; }
    inline bool fbxCopy( fbxBool1 &pDst, fbxDateTime const &pSrc )      { return false; }

    // To FbxInteger1
    inline bool fbxCopy( fbxInteger1 &pDst,fbxBool1 const &pSrc )           { pDst   = (fbxInteger1)pSrc; return true; }
//  inline bool fbxCopy( fbxInteger1 &pDst,fbxInteger1 const &pSrc )        { pDst   = (fbxInteger1)pSrc; return true; }
    inline bool fbxCopy( fbxInteger1 &pDst,fbxFloat1 const &pSrc )      { pDst   = (fbxInteger1)pSrc; return true; }
    inline bool fbxCopy( fbxInteger1 &pDst,fbxDouble1 const &pSrc )     { pDst   = (fbxInteger1)pSrc; return true; }
    inline bool fbxCopy( fbxInteger1 &pDst,fbxDouble2 const &pSrc )     { return false; }
    inline bool fbxCopy( fbxInteger1 &pDst,fbxDouble3 const &pSrc )     { return false; }
    inline bool fbxCopy( fbxInteger1 &pDst,fbxDouble4 const &pSrc )     { return false; }
    inline bool fbxCopy( fbxInteger1 &pDst,fbxDouble44 const &pSrc )        { return false; }
//  inline bool fbxCopy( fbxInteger1 &pDst,fbxEnum const &pSrc )            { return false; }
    inline bool fbxCopy( fbxInteger1 &pDst,fbxString const &pSrc )      { return fbxCopyStr(pDst,pSrc); }
    inline bool fbxCopy( fbxInteger1 &pDst,fbxTime const &pSrc )            { return false; }
    inline bool fbxCopy( fbxInteger1 &pDst,fbxReference const &pSrc )       { return false; }
    inline bool fbxCopy( fbxInteger1 &pDst,fbxBlob const &pSrc )        { return false; }
    inline bool fbxCopy( fbxInteger1 &pDst,fbxDistance const &pSrc )        { return false; }
    inline bool fbxCopy( fbxInteger1 &pDst,fbxDateTime const &pSrc )        { return false; }

    // To FbxFloat1
    inline bool fbxCopy( fbxFloat1 &pDst,fbxBool1 const &pSrc )         { pDst   = (fbxFloat1)pSrc; return true; }
    inline bool fbxCopy( fbxFloat1 &pDst,fbxInteger1 const &pSrc )      { pDst   = (fbxFloat1)pSrc; return true; }
//  inline bool fbxCopy( fbxFloat1 &pDst,fbxFloat1 const &pSrc )        { pDst   = (fbxFloat1)pSrc; return true; }
    inline bool fbxCopy( fbxFloat1 &pDst,fbxDouble1 const &pSrc )       { pDst   = (fbxFloat1)pSrc; return true; }
    inline bool fbxCopy( fbxFloat1 &pDst,fbxDouble2 const &pSrc )       { return false; }
    inline bool fbxCopy( fbxFloat1 &pDst,fbxDouble3 const &pSrc )       { return false; }
    inline bool fbxCopy( fbxFloat1 &pDst,fbxDouble4 const &pSrc )       { return false; }
    inline bool fbxCopy( fbxFloat1 &pDst,fbxDouble44 const &pSrc )      { return false; }
//  inline bool fbxCopy( fbxFloat1 &pDst,fbxEnum const &pSrc )          { return false; }
    inline bool fbxCopy( fbxFloat1 &pDst,fbxString const &pSrc )        { return false; }
    inline bool fbxCopy( fbxFloat1 &pDst,fbxTime const &pSrc )          { return false; }
    inline bool fbxCopy( fbxFloat1 &pDst,fbxReference const &pSrc )     { return false; }
    inline bool fbxCopy( fbxFloat1 &pDst,fbxBlob const &pSrc )          { return false; }
    inline bool fbxCopy( fbxFloat1 &pDst,fbxDistance const &pSrc )      { pDst = pSrc.internalValue(); return true; }
    inline bool fbxCopy( fbxFloat1 &pDst,fbxDateTime const &pSrc )      { return false; }

    // To FbxDouble1
    inline bool fbxCopy( fbxDouble1 &pDst,fbxBool1 const &pSrc )        { pDst   = (fbxDouble1)pSrc;        return true; }
    inline bool fbxCopy( fbxDouble1 &pDst,fbxInteger1 const &pSrc )     { pDst   = (fbxDouble1)pSrc;        return true; }
    inline bool fbxCopy( fbxDouble1 &pDst,fbxFloat1 const &pSrc )       { pDst   = (fbxDouble1)pSrc;        return true; }
//  inline bool fbxCopy( fbxDouble1 &pDst,fbxDouble1 const &pSrc )      { return internalfbxCopy(pDst,pSrc); }
    inline bool fbxCopy( fbxDouble1 &pDst,fbxDouble2 const &pSrc )      { pDst   = (fbxDouble1)pSrc[0];     return true; }
    inline bool fbxCopy( fbxDouble1 &pDst,fbxDouble3 const &pSrc )      { pDst   = (fbxDouble1)pSrc[0];     return true; }
    inline bool fbxCopy( fbxDouble1 &pDst,fbxDouble4 const &pSrc )      { pDst   = (fbxDouble1)pSrc[0];     return true; }
    inline bool fbxCopy( fbxDouble1 &pDst,fbxDouble44 const &pSrc )     { pDst   = (fbxDouble1)pSrc[0][0];  return true; }
//  inline bool fbxCopy( fbxDouble1 &pDst,fbxEnum const &pSrc )         { return false; }
    inline bool fbxCopy( fbxDouble1 &pDst,fbxString const &pSrc )       { return fbxCopyStr(pDst,pSrc); }
    inline bool fbxCopy( fbxDouble1 &pDst,fbxTime const &pSrc )         { pDst   = (fbxDouble1)pSrc.GetSecondDouble();  return true; }
//  inline bool fbxCopy( fbxDouble1 &pDst,fbxReference const &pSrc )    { return false; }
//  inline bool fbxCopy( fbxDouble1 &pDst,fbxBlob const &pSrc )         { return false; }
    inline bool fbxCopy( fbxDouble1 &pDst,fbxDistance const &pSrc )     { pDst = pSrc.internalValue(); return true; }
//    inline bool fbxCopy( fbxDouble1 &pDst,fbxDateTime const &pSrc )     { return false; }

    // To fbxDouble2
    inline bool fbxCopy( fbxDouble2 &pDst,fbxBool1 const &pSrc )        { pDst   = (fbxDouble1)pSrc; return true;  }
    inline bool fbxCopy( fbxDouble2 &pDst,fbxInteger1 const &pSrc )     { pDst   = (fbxDouble1)pSrc; return true;  }
    inline bool fbxCopy( fbxDouble2 &pDst,fbxFloat1 const &pSrc )       { pDst   = (fbxDouble1)pSrc; return true;  }
    inline bool fbxCopy( fbxDouble2 &pDst,fbxDouble1 const &pSrc )      { pDst   = (fbxDouble1)pSrc; return true;  }

    // To fbxDouble3
    inline bool fbxCopy( fbxDouble3 &pDst,fbxBool1 const &pSrc )        { pDst   = (fbxDouble1)pSrc; return true;  }
    inline bool fbxCopy( fbxDouble3 &pDst,fbxInteger1 const &pSrc )     { pDst   = (fbxDouble1)pSrc; return true;  }
    inline bool fbxCopy( fbxDouble3 &pDst,fbxFloat1 const &pSrc )       { pDst   = (fbxDouble1)pSrc; return true;  }
    inline bool fbxCopy( fbxDouble3 &pDst,fbxDouble1 const &pSrc )      { pDst   = (fbxDouble1)pSrc; return true;  }
    inline bool fbxCopy( fbxDouble3 &pDst,fbxDouble2 const &pSrc )      { return false;  }
//  inline bool fbxCopy( fbxDouble3 &pDst,fbxDouble3 const &pSrc )      { return internalfbxCopy3(pSrc,pDst);  }
    inline bool fbxCopy( fbxDouble3 &pDst,fbxDouble4 const &pSrc )      { pDst   = pSrc; return true; }
    inline bool fbxCopy( fbxDouble3 &pDst,fbxDouble44 const &pSrc )     { return false; }
//  inline bool fbxCopy( fbxDouble4 &pDst,fbxEnum const &pSrc )         { return false; }
    inline bool fbxCopy( fbxDouble3 &pDst,fbxString const &pSrc )       { return false; }
    inline bool fbxCopy( fbxDouble3 &pDst,fbxTime const &pSrc )         { return false; }
    inline bool fbxCopy( fbxDouble3 &pDst,fbxReference const &pSrc )    { return false; }
    inline bool fbxCopy( fbxDouble3 &pDst,fbxBlob const &pSrc )         { return false; }
    inline bool fbxCopy( fbxDouble3 &pDst,fbxDistance const &pSrc )     { return false; }
    inline bool fbxCopy( fbxDouble3 &pDst,fbxDateTime const &pSrc )     { return false; }

    // To fbxDouble4
    inline bool fbxCopy( fbxDouble4 &pDst,fbxBool1 const &pSrc )        { return false; }
    inline bool fbxCopy( fbxDouble4 &pDst,fbxInteger1 const &pSrc )     { return false; }
    inline bool fbxCopy( fbxDouble4 &pDst,fbxFloat1 const &pSrc )       { return false; }
    inline bool fbxCopy( fbxDouble4 &pDst,fbxDouble1 const &pSrc )      { return false; }
    inline bool fbxCopy( fbxDouble4 &pDst,fbxDouble2 const &pSrc )      { return false; }
    inline bool fbxCopy( fbxDouble4 &pDst,fbxDouble3 const &pSrc )      { pDst   = pSrc; return true; }
    inline bool fbxCopy( fbxDouble4 &pDst,fbxDouble44 const &pSrc )     { return false; }
//  inline bool fbxCopy( fbxDouble4 &pDst,fbxEnum const &pSrc )         { return false; }
    inline bool fbxCopy( fbxDouble4 &pDst,fbxString const &pSrc )       { return false; }
    inline bool fbxCopy( fbxDouble4 &pDst,fbxTime const &pSrc )         { return false; }
    inline bool fbxCopy( fbxDouble4 &pDst,fbxReference const &pSrc )    { return false; }
    inline bool fbxCopy( fbxDouble4 &pDst,fbxBlob const &pSrc )         { return false; }
    inline bool fbxCopy( fbxDouble4 &pDst,fbxDistance const &pSrc )     { return false; }
    inline bool fbxCopy( fbxDouble4 &pDst,fbxDateTime const &pSrc )     { return false; }

    // To String
    inline bool fbxCopy( fbxString &pDst,fbxBool1 const &pSrc )         { pDst=pSrc ? "true" : "false"; return true; }
    inline bool fbxCopy( fbxString &pDst,fbxInteger1 const &pSrc )      { pDst=KString(pSrc); return true; }
    inline bool fbxCopy( fbxString &pDst,fbxFloat1 const &pSrc )        { pDst=KString(pSrc); return true; }
    inline bool fbxCopy( fbxString &pDst,fbxDouble1 const &pSrc )       { pDst=KString(pSrc); return true; }
    inline bool fbxCopy( fbxString &pDst,fbxDouble2 const &pSrc )       { pDst=KString(pSrc[0])+","+KString(pSrc[1]); return true; }
    inline bool fbxCopy( fbxString &pDst,fbxDouble3 const &pSrc )       { pDst=KString(pSrc[0])+","+KString(pSrc[1])+","+KString(pSrc[2]); return true; }
    inline bool fbxCopy( fbxString &pDst,fbxDouble4 const &pSrc )       { pDst=KString(pSrc[0])+","+KString(pSrc[1])+","+KString(pSrc[2])+","+KString(pSrc[3]); return true; }
    inline bool fbxCopy( fbxString &pDst,fbxDouble44 const &pSrc )      { pDst=KString(pSrc[0][0])+","+KString(pSrc[0][1])+","+KString(pSrc[0][2])+","+KString(pSrc[0][3]); return true; }
//  inline bool fbxCopy( fbxString &pDst,fbxString const &pSrc )        { return false; }
    inline bool fbxCopy( fbxString &pDst,fbxTime const &pSrc )          { char lTimeStr[128]; pSrc.GetTimeString(lTimeStr); pDst=lTimeStr; return true; }
    inline bool fbxCopy( fbxString &pDst,fbxReference const &pSrc )     { pDst="<reference>"; return true; }
    inline bool fbxCopy( fbxString &pDst,fbxBlob const &pSrc )          { pDst="<blob>"; return true; } // Or convert to ASCII-85?
    inline bool fbxCopy( fbxString &pDst,fbxDistance const &pSrc )      { pDst= KString(pSrc.value()) + " " +pSrc.unitName(); return true; }
    inline bool fbxCopy( fbxString &pDst,fbxDateTime const &pSrc )      { pDst= pSrc.toString(); return true; }

    // To Blob
    inline bool fbxCopy( fbxBlob &pDst,fbxBool1 const &pSrc )           { pDst.Assign(&pSrc, sizeof(pSrc)); return true; }
    inline bool fbxCopy( fbxBlob &pDst,fbxInteger1 const &pSrc )        { pDst.Assign(&pSrc, sizeof(pSrc)); return true; }
    inline bool fbxCopy( fbxBlob &pDst,fbxFloat1 const &pSrc )          { pDst.Assign(&pSrc, sizeof(pSrc)); return true; }
    inline bool fbxCopy( fbxBlob &pDst,fbxDouble1 const &pSrc )         { pDst.Assign(&pSrc, sizeof(pSrc)); return true; }
    inline bool fbxCopy( fbxBlob &pDst,fbxDouble2 const &pSrc )         { pDst.Assign(&pSrc, sizeof(pSrc)); return true; }
    inline bool fbxCopy( fbxBlob &pDst,fbxDouble3 const &pSrc )         { pDst.Assign(&pSrc, sizeof(pSrc)); return true; }
    inline bool fbxCopy( fbxBlob &pDst,fbxDouble4 const &pSrc )         { pDst.Assign(&pSrc, sizeof(pSrc)); return true; }
    inline bool fbxCopy( fbxBlob &pDst,fbxDouble44 const &pSrc )        { pDst.Assign(&pSrc, sizeof(pSrc)); return true; }
    inline bool fbxCopy( fbxBlob &pDst,fbxString const &pSrc )
    {
        bool lCastable = pSrc.GetLen() == (int)pSrc.GetLen();
        K_ASSERT( lCastable );
        if( lCastable )
            pDst.Assign(pSrc.Buffer(), (int)pSrc.GetLen());
        return lCastable;
    }
    inline bool fbxCopy( fbxBlob &pDst,fbxTime const &pSrc )            { kLongLong t = pSrc.Get(); pDst.Assign( &t, sizeof(t)); return true; }
    inline bool fbxCopy( fbxBlob &pDst,fbxReference const &pSrc )       { return false; }
    inline bool fbxCopy( fbxBlob &pDst,fbxDistance const &pSrc )        { return false; }
    inline bool fbxCopy( fbxBlob &pDst,fbxDateTime const &pSrc )        { return false; }
    //inline bool fbxCopy( fbxBlob &pDst,fbxBlob const &pSrc )          { pDst=pSrc; return true; }

    inline bool fbxCopy( fbxDistance &pDst,fbxBool1 const &pSrc )        { return false; }
    inline bool fbxCopy( fbxDistance &pDst,fbxInteger1 const &pSrc )     { return false; }
    inline bool fbxCopy( fbxDistance &pDst,fbxFloat1 const &pSrc )       { return false; }
    inline bool fbxCopy( fbxDistance &pDst,fbxDouble1 const &pSrc )      { return false; }
    inline bool fbxCopy( fbxDistance &pDst,fbxDouble2 const &pSrc )      { return false; }
    inline bool fbxCopy( fbxDistance &pDst,fbxDouble3 const &pSrc )      { return false; }
    inline bool fbxCopy( fbxDistance &pDst, fbxDouble4 const &pSrc )     { return false; }
    inline bool fbxCopy( fbxDistance &pDst,fbxDouble44 const &pSrc )     { return false; }
    inline bool fbxCopy( fbxDistance &pDst,fbxString const &pSrc )       { return false; }
    inline bool fbxCopy( fbxDistance &pDst,fbxTime const &pSrc )         { return false; }
    inline bool fbxCopy( fbxDistance &pDst,fbxReference const &pSrc )    { return false; }
    inline bool fbxCopy( fbxDistance &pDst,fbxBlob const &pSrc )         { return false; }
    inline bool fbxCopy( fbxDistance &pDst,fbxDateTime const &pSrc )     { return false; }

    inline bool fbxCopy( fbxDateTime &pDst,fbxBool1 const &pSrc )        { return false; }
    inline bool fbxCopy( fbxDateTime &pDst,fbxInteger1 const &pSrc )     { return false; }
    inline bool fbxCopy( fbxDateTime &pDst,fbxFloat1 const &pSrc )       { return false; }
    inline bool fbxCopy( fbxDateTime &pDst,fbxDouble1 const &pSrc )      { return false; }
    inline bool fbxCopy( fbxDateTime &pDst,fbxDouble2 const &pSrc )      { return false; }
    inline bool fbxCopy( fbxDateTime &pDst,fbxDouble3 const &pSrc )      { return false; }
    inline bool fbxCopy( fbxDateTime &pDst,fbxDouble4 const &pSrc )      { return false; }
    inline bool fbxCopy( fbxDateTime &pDst,fbxDouble44 const &pSrc )     { return false; }
    inline bool fbxCopy( fbxDateTime &pDst,fbxString const &pSrc )       { return pDst.fromString(pSrc); }
    inline bool fbxCopy( fbxDateTime &pDst,fbxTime const &pSrc )         { return false; }
    inline bool fbxCopy( fbxDateTime &pDst,fbxReference const &pSrc )    { return false; }
    inline bool fbxCopy( fbxDateTime &pDst,fbxBlob const &pSrc )         { return false; }
    inline bool fbxCopy( fbxDateTime &pDst,fbxDistance const &pSrc )     { return false; }

    template< class T > inline bool fbxCopy( T &pDst,void const *pSrc,EFbxType pSrcType)
    {
        switch (pSrcType) {
            case eBOOL1:    return fbxCopy( pDst,*(fbxBool1 *)pSrc );
            case eINTEGER1: return fbxCopy( pDst,*(fbxInteger1 *)pSrc );
            case eFLOAT1:   return fbxCopy( pDst,*(fbxFloat1 *)pSrc );
            case eDOUBLE1:  return fbxCopy( pDst,*(fbxDouble1 *)pSrc );
            case eDOUBLE2:  return fbxCopy( pDst,*(fbxDouble2 *)pSrc );
            case eDOUBLE3:  return fbxCopy( pDst,*(fbxDouble3 *)pSrc );
            case eDOUBLE4:  return fbxCopy( pDst,*(fbxDouble4 *)pSrc );
            case eDOUBLE44: return fbxCopy( pDst,*(fbxDouble44 *)pSrc );
            case eENUM:     return fbxCopy( pDst,*(fbxEnum *)pSrc );
            case eSTRING:   return fbxCopy( pDst,*(fbxString *)pSrc );
            case eTIME:     return fbxCopy( pDst,*(fbxTime *)pSrc );
            case eREFERENCE:
                K_ASSERT_MSG_NOW("Trying to set value on a void Reference type" );
            break;
            case eBLOB:     return fbxCopy( pDst,*(fbxBlob *)pSrc );
            case eDISTANCE:  return fbxCopy( pDst, *(fbxDistance *)pSrc );
            case eDATETIME:  return fbxCopy( pDst, *(fbxDateTime *)pSrc );
            default:
                K_ASSERT_MSG_NOW("Trying to assign an unknown type" );
        }
        return false;
    }

    template< class T > inline bool fbxCopy( void *pDst,EFbxType pDstType,T const &pSrc)
    {
        switch (pDstType) {
            case eBOOL1:    return fbxCopy( *(fbxBool1 *)pDst,pSrc    );
            case eINTEGER1: return fbxCopy( *(fbxInteger1 *)pDst,pSrc );
            case eFLOAT1:   return fbxCopy( *(fbxFloat1 *)pDst,pSrc   );
            case eDOUBLE1:  return fbxCopy( *(fbxDouble1 *)pDst,pSrc  );
            case eDOUBLE2:  return fbxCopy( *(fbxDouble2 *)pDst,pSrc  );
            case eDOUBLE3:  return fbxCopy( *(fbxDouble3 *)pDst,pSrc  );
            case eDOUBLE4:  return fbxCopy( *(fbxDouble4 *)pDst,pSrc  );
            case eDOUBLE44: return fbxCopy( *(fbxDouble44 *)pDst,pSrc );
            case eENUM:     return fbxCopy( *(fbxEnum *)pDst,pSrc     );
            case eSTRING:   return fbxCopy( *(fbxString *)pDst,pSrc   );
            case eTIME:     return fbxCopy( *(fbxTime *)pDst,pSrc   );
            case eREFERENCE:
                K_ASSERT_MSG_NOW("Trying to set value on a void Reference type" );
            break;
            case eBLOB:         return fbxCopy( *(fbxBlob *)pDst,pSrc   );
            case eDISTANCE:     return fbxCopy( *(fbxDistance *)pDst, pSrc );
            case eDATETIME:     return fbxCopy( *(fbxDateTime *)pDst, pSrc );
            default:
                K_ASSERT_MSG_NOW("Trying to assign an unknown type" );
        }
        return false;
    }

    inline bool fbxCopy( void *pDst,EFbxType pDstType,void const *pSrc,EFbxType pSrcType)
    {
        switch (pSrcType) {
            case eBOOL1:    return fbxCopy( pDst,pDstType,*(fbxBool1 *)pSrc );
            case eINTEGER1: return fbxCopy( pDst,pDstType,*(fbxInteger1 *)pSrc );
            case eFLOAT1:   return fbxCopy( pDst,pDstType,*(fbxFloat1 *)pSrc );
            case eDOUBLE1:  return fbxCopy( pDst,pDstType,*(fbxDouble1 *)pSrc );
            case eDOUBLE2:  return fbxCopy( pDst,pDstType,*(fbxDouble2 *)pSrc );
            case eDOUBLE3:  return fbxCopy( pDst,pDstType,*(fbxDouble3 *)pSrc );
            case eDOUBLE4:  return fbxCopy( pDst,pDstType,*(fbxDouble4 *)pSrc );
            case eDOUBLE44: return fbxCopy( pDst,pDstType,*(fbxDouble44 *)pSrc );
            case eENUM:     return fbxCopy( pDst,pDstType,*(fbxEnum *)pSrc );
            case eSTRING:   return fbxCopy( pDst,pDstType,*(fbxString *)pSrc);
            case eTIME:     return fbxCopy( pDst,pDstType,*(fbxTime*)pSrc);
            case eREFERENCE:
                K_ASSERT_MSG_NOW("Trying to set value on a void Reference type" );
            break;
            case eBLOB:     return fbxCopy( pDst,pDstType,*(fbxBlob*)pSrc);
            case eDISTANCE: return fbxCopy(pDst, pDstType, *(fbxDistance*)pSrc);
            case eDATETIME: return fbxCopy(pDst, pDstType, *(fbxDateTime*)pSrc);
            default:
                K_ASSERT_MSG_NOW("Trying to assign an unknown type" );
        }
        return false;
    }

    /** Creates a fbx primative type and initializes its memory.
      * \param pType The type of object to create.
      * \return A pointer to the new primative object. Note that the caller owns the returned object.
      *         The pointer returned is NULL if pType is eUNIDENTIFIED or an unknown type.
      */
    KFBX_DLL void* fbxCreate( EFbxType pType );


    /** Destroys an fbx primative type. If the return value is true
      * the memory pointed to by pData has been deleted and should
      * no longer be accessed.
      * \param pType The type of object being deleted
      * \param pData Pointer to the object being deleted.
      * \return true if the object was detroyed, false otherwise.
      */
    KFBX_DLL bool fbxDestroy( EFbxType pType, void* pData );


    /** Compare two values of the same type
      * \param pA first value
      * \param pB second value
      * \param pType The data type of both values
      * \return \c true if equal, \c false otherwise
      */
    inline bool fbxCompare( const void* pA, const void* pB, EFbxType pType )
    {
        switch (pType) {
            case eBOOL1:    return  (*(fbxBool1*)pA)    == (*(fbxBool1*)pB);
            case eINTEGER1: return  (*(fbxInteger1*)pA) == (*(fbxInteger1*)pB);
            case eFLOAT1:   return  (*(fbxFloat1*)pA)   == (*(fbxFloat1*)pB);
            case eDOUBLE1:  return  (*(fbxDouble1*)pA)  == (*(fbxDouble1*)pB);
            case eDOUBLE2:  return  (*(fbxDouble2*)pA)  == (*(fbxDouble2*)pB);
            case eDOUBLE3:  return  (*(fbxDouble3*)pA)  == (*(fbxDouble3*)pB);
            case eDOUBLE4:  return  (*(fbxDouble4*)pA)  == (*(fbxDouble4*)pB);
            case eDOUBLE44: return  (*(fbxDouble44*)pA) == (*(fbxDouble44*)pB);
            case eENUM:     return  (*(fbxEnum*)pA)     == (*(fbxEnum*)pB);
            case eSTRING:   return  (*(fbxString*)pA)   == (*(fbxString*)pB);
            case eTIME:     return  (*(fbxTime*)pA)     == (*(fbxTime*)pB);
            case eREFERENCE:
                K_ASSERT_MSG_NOW("Trying to compare value on a void Reference type" );
            break;
            case eBLOB: return (*(fbxBlob*)pA) == (*(fbxBlob*)pB);
            case eDISTANCE: return (*(fbxDistance*)pA) == (*(fbxDistance*)pB);
            case eDATETIME: return (*(fbxDateTime*)pA) == (*(fbxDateTime*)pB);
            default:
                K_ASSERT_MSG_NOW("Trying to compare an unknown type" );
        }
        return false;
    }

#include <fbxfilesdk_nsend.h>

#endif // _KFbxTypes_h


