#pragma once

namespace NAvoid {

	public enum class Direction {
		None  =  0,
		Up    =  1,
		Down  =  2,
		Left  =  4,
		Right =  8,
		All   = 15
	};

	public enum class RouterFlag {
		PolyLineRouting    = 1,
		OrthogonalRouting  = 2
	};
		

	public enum class RoutingTypes {
		PolyLine	= 1,
		Orthogonal	= 2
	};
	
	///<summary>
	/// Types of routing parameters And penalties that can be used to 
	/// tailor the style And improve the quality of the connector 
	/// routes produced.
	///</summary>
	public enum class RoutingParameters {

		///<summary>
		/// This penalty Is applied for each segment in the connector 
		/// path beyond the first.  This should always normally be set
		/// when doing orthogonal routing to prevent step-Like connector
		/// paths.
		/// This penalty must be set (i.e., be greater than zero) in 
		/// order for orthogonal connector nudging to be performed, since
		/// this requires reasonable initial routes. 
		///</summary>
		SegmentPenalty = 0,

		///<summary>
		/// This penalty Is applied in its full amount to tight acute 
		/// bends in the connector path.  A smaller portion of the penalty
		/// Is applied for slight bends, i.e., where the bend Is close to
		/// 180 degrees.  This Is useful for polyline routing where there
		/// Is some evidence that tighter corners are worse for 
		/// readability, but that slight bends might Not be so bad, 
		/// especially when smoothed by curves.
		///</summary>
		AnglePenalty,

		///<summary>
		/// This penalty Is applied whenever a connector path crosses 
		/// another connector path.  It takes shared paths into 
		/// consideration And the penalty Is only applied if there
		/// Is an actual crossing.
		/// This penalty Is still experimental!  It Is Not recommended
		/// for normal use.
		///</summary>
		CrossingPenalty,

		///<summary>
		/// This penalty Is applied whenever a connector path crosses 
		/// a cluster boundary.
		/// This penalty Is still experimental!  It Is Not recommended
		/// for normal use.
		/// This penalty Is very slow.  You can override the method
		/// Router:shouldContinueTransactionWithProgress() To check
		/// progress And possibly cancel overly slow transactions.
		///</summary>
		ClusterCrossingPenalty,

		///<summary>
		/// This penalty Is applied whenever a connector path shares 
		/// some segments with an immovable portion of an existing 
		/// connector route (such as the first Or last segment of a
		/// connector).
		/// This penalty Is still experimental!  It Is Not recommended
		/// for normal use.
		///</summary>
		FixedSharedPathPenalty,

		///<summary>
		/// <para>This penalty Is applied to port selection choice when the 
		/// other end of the connector being routed does Not appear in 
		/// any of the 90 degree visibility cones centered on the
		/// visibility directions for the port.</para>
		/// <para>This penalty Is still experimental!  It Is Not recommended
		/// for normal use.</para>
		/// <para>This penalty Is very slow.  You can override the method
		/// Router:shouldContinueTransactionWithProgress() To check
		/// progress And possibly cancel overly slow transactions.</para>
		///</summary>
		PortDirectionPenalty,

		///<summary>
		/// This parameter defines the spacing distance that will be added
		/// to the sides of each shape when determining obstacle sizes for
		/// routing.  This controls how closely connectors pass shapes, And
		/// can be used to prevent connectors overlapping with shape 
		/// boundaries. By default, this distance Is set to a value of 0.
		///</summary>
		ShapeBufferDistance,

		///<summary>
		/// This parameter defines the spacing distance that will be used
		/// for nudging apart overlapping corners And line segments of 
		/// connectors.  By default, this distance Is set to a value of 4.
		///</summary>
		IdealNudgingDistance,

		///<summary>
		/// This penalty Is applied whenever a connector path travels
		/// in the direction opposite of the destination from the source
		/// endpoint.  By default this penalty Is set to zero.  This 
		/// shouldn't be needed in most cases but can be useful if you
		/// use penalties such as :crossingPenalty which cause connectors
		/// to loop around obstacles.
		///</summary>
		ReverseDirectionPenalty
	};


	///<summary>
	/// Types of routing options that can be enabled.
	///</summary>
	public enum class RoutingOptions {

		///<summary><para>
		/// This option causes the final segments of connectors, which are 
		/// attached to shapes, to be nudged apart.  Usually these segments 
		/// are fixed, since they are considered to be attached to ports.</para>
		/// 
		/// <para>Defaults to false.</para>
		///
		/// <para>This option also causes routes running through the same checkpoint 
		/// to be nudged apart.</para>
		///
		/// <para>This option has no effect if :nudgeSharedPathsWithCommonEndPoint Is
		///set To False,
		///
		/// This will allow routes to be nudged up to the bounds of shapes.</para>
		///
		///</summary>
		nudgeOrthogonalSegmentsConnectedToShapes = 0,

		///<summary>
		/// <para>This option causes hyperedge routes to be locally improved fixing
		/// obviously bad paths.  As part of this process libavoid will
		/// effectively move junctions, setting New ideal positions which can be
		/// accessed via JunctionRef:recommendedPosition() For Each junction.</para>
		///
		/// <para>Defaults to true.</para>
		///
		/// <para>This will Not add Or remove junctions, so will keep the hyperedge
		/// topology the same.  Better routes can be achieved by enabling the
		/// :improveHyperedgeRoutesMovingAddingAndDeletingJunctions option.</para>
		///
		/// <para>If initial sensible positions for junctions in hyperedges are Not
		/// known you can register those hyperedges with the HyperedgeRerouter
		/// class for complete rerouting.</para>
		///
		///</summary>
		improveHyperedgeRoutesMovingJunctions,

		///<summary>
		/// <para>This option penalises And attempts to reroute orthogonal shared 
		/// connector paths terminating at a common junction Or shape 
		/// connection pin.  When multiple connector paths enter Or leave 
		/// the same side of a junction (Or shape pin), the router will 
		/// attempt to reroute these to different sides of the junction Or 
		/// different shape pins. </para>
		///
		/// <para>Defaults to false.</para>
		///
		/// <para>This option depends on the :fixedSharedPathPenalty penalty having 
		/// been set.</para>
		///
		///</summary>
		penaliseOrthogonalSharedPathsAtConnEnds,

		///<summary>
		/// <para>This option can be used to control whether collinear line 
		/// segments that touch just at their ends will be nudged apart.
		/// The overlap will usually be resolved in the other dimension,
		/// so this Is Not usually required.</para>
		///
		/// <para>Defaults to false.</para>
		///
		///</summary>
		nudgeOrthogonalTouchingColinearSegments,

		///<summary>
		/// <para>This option can be used to control whether the router performs
		/// a preprocessing step before orthogonal nudging where Is tries
		/// to unify segments And centre them in free space.  This 
		/// generally results in better quality ordering And nudging.</para>
		///         
		/// <para>Defaults to true.</para>
		///
		/// <para>You may wish to turn this off for large examples where it
		/// can be very slow And will make little difference.</para>
		///
		///</summary>
		performUnifyingNudgingPreprocessingStep,

		///<summary>
		/// <para>This option causes hyperedge routes to be locally improved fixing
		/// obviously bad paths.</para>
		/// 
		/// <para>It can cause junctions And connectors to be added Or removed from
		/// hyperedges.  To get details of these changes for each connector you can
		/// call Router:newAndDeletedObjectListsFromHyperedgeImprovement().</para>
		///
		/// <para>As part of this process libavoid will effectively move junctions by
		/// setting New ideal positions for each remaining Or added junction, 
		/// which can be read from JunctionRef:recommendedPosition() For Each 
		/// junction.</para>
		///
		/// <para>Defaults to false.</para>
		///
		/// <para>If set, this option overrides the :improveHyperedgeRoutesMovingJunctions
		/// option.</para>
		///
		/// <para>If initial sensible positions for junctions in hyperedges are Not
		/// known you can register those hyperedges with the HyperedgeRerouter
		/// class for complete rerouting.</para>
		///
		///</summary>
		improveHyperedgeRoutesMovingAddingAndDeletingJunctions,

		///<summary>
		/// <para>This option determines whether intermediate segments of connectors that
		/// are attached to common endpoints will be nudged apart.  Usually these
		/// segments get nudged apart, but you may want to turn this off if you would
		/// prefer that entire shared paths terminating at a common end point should
		/// overlap. </para>
		///
		/// <para>Defaults to true.</para>
		///</summary>		
		nudgeSharedPathsWithCommonEndPoint
	};


}
