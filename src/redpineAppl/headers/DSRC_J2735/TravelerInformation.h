/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "J2735.asn"
 */

#ifndef	_TravelerInformation_H_
#define	_TravelerInformation_H_


#include <asn_application.h>

/* Including external dependencies */
#include "DSRCmsgID.h"
#include "UniqueMSGID.h"
#include "URL-Base.h"
#include "Count.h"
#include "MsgCRC.h"
#include <asn_SEQUENCE_OF.h>
#include "TravelerInfoType.h"
#include "DYear.h"
#include "MinuteOfTheYear.h"
#include "MinutesDuration.h"
#include "SignPrority.h"
#include "LaneWidth.h"
#include "DirectionOfUse.h"
#include "URL-Short.h"
#include "FurtherInfoID.h"
#include "RoadSignID.h"
#include <constr_CHOICE.h>
#include <constr_SEQUENCE_OF.h>
#include "ITIScodesAndText.h"
#include "WorkZone.h"
#include "GenericSignage.h"
#include "SpeedLimit.h"
#include "ExitService.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum msgId_PR {
	msgId_PR_NOTHING,	/* No components present */
	msgId_PR_furtherInfoID,
	msgId_PR_roadSignID
} msgId_PR;
typedef enum content_PR {
	content_PR_NOTHING,	/* No components present */
	content_PR_advisory,
	content_PR_workZone,
	content_PR_genericSign,
	content_PR_speedLimit,
	content_PR_exitService
} content_PR;

/* Forward declarations */
struct Position3D;
struct ValidRegion;

/* TravelerInformation */
typedef struct TravelerInformation {
	DSRCmsgID_t	 msgID;
	UniqueMSGID_t	*packetID	/* OPTIONAL */;
	URL_Base_t	*urlB	/* OPTIONAL */;
	Count_t	*dataFrameCount	/* OPTIONAL */;
	struct dataFrames {//a4
		A_SEQUENCE_OF(struct Member1 {//30
			TravelerInfoType_t	 frameType;//80
			struct msgId {//a1
				msgId_PR present;//80
				union msgId_u {//a1
					FurtherInfoID_t	 furtherInfoID; //a0
					RoadSignID_t	 roadSignID; //a1
				} choice;
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} msgId;
			DYear_t	*startYear	/* OPTIONAL */; //82
			MinuteOfTheYear_t	 startTime;  //83
			MinutesDuration_t	 duratonTime;  //84
			SignPrority_t	 priority;   //85
			struct Position3D	*commonAnchor; //a6	/* OPTIONAL */;
			LaneWidth_t	*commonLaneWidth ;   //87	/* OPTIONAL */;
			DirectionOfUse_t	*commonDirectionality;//88  	/* OPTIONAL */;
			struct regions {//a9
				A_SEQUENCE_OF(struct ValidRegion) list;
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} regions;
			struct content {
				content_PR present;
				union content_u {
					ITIScodesAndText_t	 advisory;
					WorkZone_t	 workZone;
					GenericSignage_t	 genericSign;
					SpeedLimit_t	 speedLimit;
					ExitService_t	 exitService;
				} choice;
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} content;
			URL_Short_t	*url	/* OPTIONAL */;
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} ) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} dataFrames;
	MsgCRC_t	 crc;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TravelerInformation_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TravelerInformation;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "Position3D.h"
#include "ValidRegion.h"

#endif	/* _TravelerInformation_H_ */
#include <asn_internal.h>